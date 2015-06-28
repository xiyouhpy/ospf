// =====================================================================================
// 
//       Filename:  Mutex.h
//
//    Description:  互斥锁的封装
//
// =====================================================================================

#ifndef MUTEX_H_
#define MUTEX_H_

#include <pthread.h>

#include "noncopyable.h"

namespace ospf {

/**
 * 原始互斥锁的封装
 */
class MutexLock : private noncopyable
{
public:
	/// 构造函数
	MutexLock()
	{
		pthread_mutexattr_t attr;

		pthread_mutexattr_init(&attr);
		/// 初始化互斥锁类型为 PTHREAD_MUTEX_NORMAL
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
		pthread_mutex_init(&mutex_, &attr);
		pthread_mutexattr_destroy(&attr);
	}
	
	/// 析构函数
	~MutexLock()
	{
		pthread_mutex_destroy(&mutex_);
	}

	/// 加锁函数（仅允许 MutexLockGuard 类调用）
	void lock()
	{
		pthread_mutex_lock(&mutex_);
	}

	/// 解锁函数（仅允许 MutexLockGuard 类调用）
	void unlock()
	{
		pthread_mutex_unlock(&mutex_);
	}

	/// 返回原始互斥锁类型的指针（仅允许 Condition 类调用）
	pthread_mutex_t *getPthreadMutex()
	{
		return &mutex_;
	}

private:
	pthread_mutex_t mutex_;
};

/**
 * MutexLock 互斥锁的加/解锁类
 */
class MutexLockGuard : private noncopyable
{
public:
	/// 构造函数自动加锁
	explicit MutexLockGuard(MutexLock &mutex) : mutex_(mutex)
	{
		mutex_.lock();
	}

	/// 脱离作用域的时候自动解锁
	~MutexLockGuard()
	{
		mutex_.unlock();
	}

private:
	MutexLock &mutex_;
};

/**
 * 下面的宏防止出现诸如 MutexLockGuard(mutex) 的定义
 * 正规做法是 MutexLockGuard lock(mutex)
 */
#define MutexLockGuard(x) static_assert(false, "missing mutex guarg var name!")

}

#endif 	// MUTEX_H_
