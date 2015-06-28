// =====================================================================================
// 
//       Filename:  Thread.cpp
//
//    Description:  Linux POSIX 线程
// 
// =====================================================================================

#include <memory>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <linux/unistd.h>

#include "CurrentThread.h"
#include "Thread.h"

namespace ospf {

namespace CurrentThread {

	/// 缓存线程tid，避免频繁系统调用
	__thread int t_cachedTid = 0;

	/// 线程tid的字符表示
	__thread char t_tidString[32];

	/// 线程名
	__thread const char *t_threadName = "unknown";
	
	// 中断产生标记
	__thread bool is_intr = false;
	
	// 中断号
	__thread int intr_no = 0;
}

namespace detail {

/// 获得线程tid
pid_t gettid()
{
	return static_cast<pid_t>(::syscall(SYS_gettid));
}

/// 子线程创建后初始化
void afterFork()
{
	ospf::CurrentThread::t_cachedTid = 0;
	ospf::CurrentThread::t_threadName = "main";
	CurrentThread::tid();
}

/// 线程名初始化
class ThreadNameInitializer
{
public:
	/// 构造函数
	ThreadNameInitializer()
	{
		ospf::CurrentThread::t_threadName = "main";
		
		// 缓存当前线程 tid
		CurrentThread::tid();
		
		// 假如当前线程被 fork，那么执行 afterFork 为其重新初始化一些数据
		pthread_atfork(NULL, NULL, &afterFork);
	}
};

/// 定义一个全局对象，使得主线程被初始化
ThreadNameInitializer init;

/// 线程数据
class ThreadData
{
public:
	typedef ospf::Thread::ThreadFunc ThreadFunc;
	ThreadFunc func_;
	std::string name_;
	std::weak_ptr<pid_t> wkTid_;

	/// 构造函数
	ThreadData(const ThreadFunc &func, const std::string &name, const std::shared_ptr<pid_t>& tid)
		: func_(func),
		  name_(name),
		  wkTid_(tid)
	{
	}

	/// 运行线程
	void runInThread()
	{
		pid_t tid = ospf::CurrentThread::tid();

		std::shared_ptr<pid_t> ptid = wkTid_.lock();
		if (ptid) {
			*ptid = tid;
			ptid.reset();
		}
		ospf::CurrentThread::t_threadName = name_.empty() ? "ospfThread" : name_.c_str();
		::prctl(PR_SET_NAME, ospf::CurrentThread::t_threadName);
		
		// 运行线程函数
		func_();
	}
};

/// 运行线程函数
void *startThread(void *obj)
{
	ThreadData* data = static_cast<ThreadData *>(obj);
	data->runInThread();
	delete data;

	return NULL;
}

}
}

using namespace ospf;

/// 缓存线程tid
void CurrentThread::cacheTid()
{
	if (t_cachedTid == 0) {
		t_cachedTid = detail::gettid();
		snprintf(t_tidString, sizeof(t_tidString), "%5d ", t_cachedTid);
	}
}

/// 判断当前线程是否是主线程
bool CurrentThread::isMainThread()
{
	return (tid() == ::getpid());
}

/// 休眠函数
void CurrentThread::sleepUsec(int64_t usec)
{
	struct timespec ts = { 0, 0 };
	ts.tv_sec = static_cast<time_t>(usec / 1000000);
	ts.tv_nsec = static_cast<long>(usec % 1000000 * 1000);
	::nanosleep(&ts, NULL);
}

AtomicInt32 Thread::numCreated_;

/// 构造函数
Thread::Thread(const ThreadFunc &func, const std::string &tname)
	: started_(false),
	  joined_(false),
	  pthreadId_(0),
	  tid_(new pid_t(0)),
	  func_(func),
	  name_(tname)
{
	setDefaultName();
}

/// 析构函数
Thread::~Thread()
{
	if (started_ && !joined_) {
		pthread_detach(pthreadId_);
	}
}

/// 启动线程
void Thread::start()
{
	assert(!started_);
	started_ = true;
	detail::ThreadData *data = new detail::ThreadData(func_, name_, tid_);
	if (pthread_create(&pthreadId_, NULL, &detail::startThread, data)) {
		started_ = false;
		delete data;
	}
}

/// 等待线程结束
int Thread::join()
{
	assert(started_);
	assert(!joined_);
	joined_ = true;

	return pthread_join(pthreadId_, NULL);
}

void Thread::setDefaultName()
{
	int num = numCreated_.incrementAndGet();
	if (name_.empty()) {
		char buf[32];
		snprintf(buf, sizeof buf, "Thread%d", num);
		name_ = buf;
	}
}

