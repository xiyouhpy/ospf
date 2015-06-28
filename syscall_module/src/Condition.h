// =====================================================================================
// 
//       Filename:  Condition.h
//
//    Description:  条件变量的封装
//
// =====================================================================================

#ifndef CONDITION_H_
#define CONDITION_H_

#include <pthread.h>
#include <time.h>

#include "noncopyable.h"
#include "Mutex.h"

namespace ospf {

/**
 * 条件变量的封装类
 */
class Condition : private noncopyable
{
public:
	/// 构造函数
	explicit Condition(MutexLock &mutex) : mutex_(mutex)
	{
		pthread_cond_init(&pcond_, NULL);
	}

	/// 析构函数
	~Condition()
	{
		pthread_cond_destroy(&pcond_);
	}

	/// 等待该条件变量
	void wait()
	{
		pthread_cond_wait(&pcond_, mutex_.getPthreadMutex());
	}

	/// 通知一个等待该条件变量的线程
	void notify()
	{
		pthread_cond_signal(&pcond_);
	}

	/// 等待指定时间后返回
	bool waitForSeconds(int seconds)
	{
		struct timespec abstime;

		clock_gettime(CLOCK_REALTIME, &abstime);
		abstime.tv_sec += seconds;

		return (ETIMEDOUT == pthread_cond_timedwait(&pcond_, mutex_.getPthreadMutex(), &abstime));
	}

	/// 通知所有等待该条件变量的线程
	void notifyAll()
	{
		pthread_cond_broadcast(&pcond_);
	}

private:
	MutexLock &mutex_;
	pthread_cond_t pcond_;
};

}

#endif 	// CONDITION_H_
