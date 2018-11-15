#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_
#include <iostream>
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
	}
	
	~SmartPointer() {
		cout << "Release smart pointer at "<< \
		static_cast<const void*>(mPointer) << endl;
	}

private:
	T *mPointer;
};
#endif
