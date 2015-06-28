// =====================================================================================
// 
//       Filename:  noncopyable.h
//
//    Description:  继承后不允许拷贝的基类
//
// =====================================================================================

#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

namespace ospf {

/**
 * 私有继承该类使得子类不允许赋值和拷贝
 */
class noncopyable 
{
protected:
	noncopyable() {}
	~noncopyable() {}

private:
	noncopyable(const noncopyable &);
	const noncopyable &operator=(const noncopyable &);
};

}

#endif 	// NONCOPYABLE_H_
