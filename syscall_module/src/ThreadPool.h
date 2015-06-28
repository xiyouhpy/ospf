// =====================================================================================
// 
//       Filename:  ThreadPool.h
//
//    Description:  线程池
//
// =====================================================================================

#ifndef BASE_THREADPOOL_H_
#define BASE_THREADPOOL_H_

#include <vector>
#include <deque>
#include <string>
#include <functional>
#include <assert.h>

#include "Condition.h"
#include "Mutex.h"
#include "Thread.h"
#include "noncopyable.h"

namespace ospf {

class ThreadPool : noncopyable
{
public:
	typedef std::function<void()> Task;

	/// 构造函数
	explicit ThreadPool(const std::string &name = std::string("ThreadPool"));

	/// 析构函数
	~ThreadPool();
	
	/// 设置任务队列长度
	void setMaxQueueSize(int maxSize)
	{
		assert(maxSize > 0);
		maxQueueSize_ = maxSize;
	}

	/// 启动线程池
	void start(int numThreads);

	/// 结束线程池
	void stop();

	/// 添加一个任务
	void run(const Task &task);

private:
	void runInThread();
	Task take();

	MutexLock mutex_;
	Condition notEmpty_;
	Condition notFull_;
	std::string name_;
	std::vector<ospf::Thread *> pthreads_;
	std::deque<Task> queue_;
	size_t maxQueueSize_;
	bool running_;
};

}

#endif 	// BASE_THREADPOOL_H_
