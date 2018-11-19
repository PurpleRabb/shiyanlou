#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_
#include <iostream>

class RefBase{ //引用计数基类
public:
	RefBase() : mCount(0){}
	void incRefCount() {
		mCount++;
	}
	int decRefCount() {
		return --mCount;
	}
	int getRefCount() {
		return mCount;
	}
	virtual ~RefBase(){};
private:
	int mCount;
};
using namespace std;

template <typename T>
class SmartPointer {
public:
	SmartPointer():mPointer(NULL) {
		cout << "Create unknown smart pointer" << endl;
	}

	SmartPointer(T *p):mPointer(p) {
		cout << "Create smart pointer at "<< \
		static_cast<const void*>(p) << endl;
		if(mPointer)
			mPointer->incRefCount();
	}
	
	~SmartPointer() {
		cout << "Release smart pointer at "<< \
		static_cast<const void*>(mPointer) << endl;
		if(mPointer && mPointer->decRefCount()==0)
			delete mPointer;
	}
	
	//拷贝构造函数
	SmartPointer(const SmartPointer &other):mPointer(other.mPointer) {
		cout << "Copy constructor" << endl;
		if(mPointer)
			mPointer->incRefCount();
	}

	//赋值操作符
	SmartPointer &operator = (const SmartPointer &other) {
		T *temp(other.mPointer);
		// 新指向对象，引用计数值加1
		if(temp)
			temp->incRefCount();
		// 原指向对象，引用计数值减1，如果减1后引用计数为0 销毁原资源对象
		if(mPointer && mPointer->decRefCount() == 0)
			delete mPointer;
		// 智能指针指向新资源对象
		mPointer = temp;
		return *this;
	}
private:
	T *mPointer;
};
#endif
