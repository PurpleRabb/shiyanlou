#include <iostream>
#include "smartpointer.h"

class SomeClass {
public:
	SomeClass() {
		cout << "SomeClass constructor" << endl;	
	}
};

void testcase1() {
	SmartPointer<char> spunknown;
	SmartPointer<char> spnull = NULL;
	SmartPointer<SomeClass> spclass = new SomeClass;
	SmartPointer<const char> spstr = "Hello";
}

int main(void)
{
	testcase1();
	return 0;
}
