// =====================================================================================
// 
//       Filename:  Thread.h
//
//    Description:  Linux POSIX 线程
//
// =====================================================================================

#ifndef THREAD_H_
#define THREAD_H_

#include <functional>
#include <memory>
#include <string>
#include <unistd.h>
#include <pthread.h>

#include "Atomic.h"
#include "noncopyable.h"

namespace ospf {

/**
 * 线程类
 */
class Thread : noncopyable
{
public:
	typedef std::function<void()> ThreadFunc;

	/// 构造函数
	explicit Thread(const ThreadFunc &, const std::string &tname = std::string(""));

	/// 析构函数
	~Thread();

	/// 启动线程
	void start();

	/// 等待线程结束
	int join();

	/// 线程是否启动
	bool started() const
	{
		return started_;
	}

	/// 获取线程tid
	pid_t tid()
	{
		return *tid_;
	}

	/// 获取线程名
	const std::string &name() const
	{
		return name_;
	}

	/// 当前创建的线程数量
	static int numCreated()
	{
		return numCreated_.get();
	}

private:
	void setDefaultName();

	bool started_;
	bool joined_;
	pthread_t pthreadId_;
	std::shared_ptr<pid_t> tid_;
	ThreadFunc func_;
	std::string name_;

	static AtomicInt32 numCreated_;
};

}

#endif 	// THREAD_H_
