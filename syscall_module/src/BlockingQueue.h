// =====================================================================================
// 
//       Filename:  BlockingQueue.h
//
//    Description:  生产者/消费者队列
//
// =====================================================================================

#ifndef BLOCKINGQUEUE_H_
#define BLOCKINGQUEUE_H_

#include <deque>

#include "Condition.h"
#include "Mutex.h"
#include "noncopyable.h"

namespace ospf {

/**
 * 生产者/消费者队列
 */
template <typename T>
class BlockingQueue : noncopyable
{
public:
	/// 构造函数
	BlockingQueue() 
		: mutex_(), 
		  notEmpty_(mutex_), 
		  queue_()
	{
	}

	///  析构函数
	~BlockingQueue()
	{
	}

	/// 添加任务
	void put(T x)
	{
		MutexLockGuard lock(mutex_);
		queue_.push_back(x);
		notEmpty_.notify();
	}

	/// 取得任务
	T take()
	{
		MutexLockGuard lock(mutex_);
		
		/// 必须while，避免虚假唤醒
		while (queue_.empty()) {
			notEmpty_.wait();
		}
		T front(queue_.front());
		queue_.pop_front();

		return front;
	}

	/// 获得队列长度
	size_t size() const
	{
		MutexLockGuard lock(mutex_);

		return queue_.size();
	}

	/// 判断队列是否为空
	bool empty() const
	{
		MutexLockGuard lock(mutex_);

		return queue_.empty();
	}

private:
	mutable MutexLock mutex_;
	Condition notEmpty_;
	std::deque<T> queue_;
};

}

#endif 	// BLOCKINGQUEUE_H_

