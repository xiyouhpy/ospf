// =====================================================================================
// 
//       Filename:  CurrentThread.h
//
//    Description:  线程相关
//
// =====================================================================================

#ifndef CURRENTTHREAD_H_
#define CURRENTTHREAD_H_

#include <stdint.h>

namespace ospf {

namespace CurrentThread {

	/// 缓存线程tid，避免频繁系统调用
	extern __thread int t_cachedTid;

	/// 线程tid的字符表示
	extern __thread char t_tidString[32];

	/// 线程名
	extern __thread const char *t_threadName;
	
	// 中断产生标记
	extern __thread bool is_intr;
	
	// 中断号
	extern __thread int intr_no;

	// 缓存线程tid
	void cacheTid();

	/// 返回线程tid
	inline int tid()
	{
		if (t_cachedTid == 0) {
			cacheTid();
		}
		
		return t_cachedTid;
	}

	/// 返回字符串表示的tid
	inline const char *tidString()
	{
		return t_tidString;
	}

	/// 返回线程名
	inline const char *name()
	{
		return t_threadName;
	}

	/// 判断当前线程是否是主线程
	bool isMainThread();

	/// 休眠函数
	void sleepUsec(int64_t usec);
}
}

#endif 	// SOCX_CURRENTTHREAD_H_
