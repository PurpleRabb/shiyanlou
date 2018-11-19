#include <iostream>
#include "smartpointer.h"

class SomeClass: public RefBase {
public:
	SomeClass() {
		cout << "SomeClass constructor" << endl;
	}
	~SomeClass() {
		cout << "SomeClass deconstructor" << endl;
	}
};

class OtherClass: public RefBase {
public:
	OtherClass() {
		cout << "OtherClass constructor" << endl;
	}
	~OtherClass() {
		cout << "OtherClass deconstructor" << endl;
	}
};

/*void testcase1() {
	SmartPointer<char> spunknown;
	SmartPointer<char> spnull = NULL;
	SmartPointer<SomeClass> spclass = new SomeClass;
	SmartPointer<const char> spstr = "Hello";
}*/

void testcase3() {
	SomeClass *pSomeClass = new SomeClass();
	SmartPointer<SomeClass> spOuter = pSomeClass;
	cout << "SomeClass Ref Count:" << pSomeClass->getRefCount() << " outer.1"<< endl;
	{
		SmartPointer<SomeClass> spInner = spOuter;
		cout << "SomeClass Ref Count:" << pSomeClass->getRefCount() << " inner." << endl;
	}
	cout << "SomeClass Ref Count:" << pSomeClass->getRefCount() << " outer.2"<< endl;

	cout << "New another someclass for spOuter:" << endl;
	SmartPointer<SomeClass> spOuter2 = new SomeClass();
	spOuter = spOuter2;
}

int main(void)
{
	testcase3();
	return 0;
}
