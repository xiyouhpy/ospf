// =====================================================================================
// 
//       Filename:  ThreadPool.cpp
//
//    Description:  线程池
// 
// =====================================================================================

#include <stdio.h>

#include "ThreadPool.h"

using namespace ospf;

/// 构造函数
ThreadPool::ThreadPool(const std::string &name)
	: mutex_(),
	  notEmpty_(mutex_),
	  notFull_(mutex_),
	  name_(name),
	  maxQueueSize_(0),
	  running_(false)
{
}

/// 析构函数
ThreadPool::~ThreadPool()
{
	if (running_) {
		stop();
	}
}

/// 启动线程池
void ThreadPool::start(int numThreads)
{
	assert(!running_);
	running_ = true;

	for (size_t i = 0; i < pthreads_.size(); ++i) {
		delete pthreads_[i];
	}
	pthreads_.clear();
	
	for (int i = 0; i < numThreads; ++i) {
		char id[32];
		snprintf(id, sizeof(id), "%d", i+1);
		pthreads_.push_back(new ospf::Thread(std::bind(&ThreadPool::runInThread, this), name_+id));
		pthreads_[i]->start();
	}
}

/// 结束线程池
void ThreadPool::stop()
{
	{
		MutexLockGuard lock(mutex_);
		running_ = false;
		notEmpty_.notifyAll();
	}
	
	for (auto &thread : pthreads_) {
		thread->join();
	}
}

/// 添加一个任务
void ThreadPool::run(const Task &task)
{
	MutexLockGuard lock(mutex_);
	assert(!pthreads_.empty());
	while (queue_.size() >= maxQueueSize_) {
		notFull_.wait();
	}
	queue_.push_back(task);
	notEmpty_.notify();
}

void ThreadPool::runInThread()
{
	while (running_) {
		Task task(take());
		if (task) {
			task();
		}
	}
}

ThreadPool::Task ThreadPool::take()
{
	MutexLockGuard lock(mutex_);

	while (queue_.empty() && running_) {
		notEmpty_.wait();
	}

	Task task;
	if (!queue_.empty()) {
		task = queue_.front();
		queue_.pop_front();
		if (maxQueueSize_ > 0) {
			notFull_.notify();
		}
	}

	return task;
}

