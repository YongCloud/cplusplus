/*
 * diamond inheritance and ambiguity
 *
 * author xingjian
 * since 2019/12/21
 */
#include <iostream>
using namespace std;

// abstract class
class ABC {
	public:
		virtual float getLength() = 0;
};

// virtual extension, ABC as a Virtual Base Class
class B:virtual public ABC {
	public:
		void print() {
			cout<<getLength()<<endl;
		}
};

// virtual extension, ABC as a Virtual Base Class
class C:virtual public ABC {
	public:
		void print() {
			cout<<getLength()<<endl;
		}
};

class D:public C,public B {
	public:
		void print() {
			// [Error] reference to 'getLength' is ambiguous
			// cout<<getLength()<<endl;

			// first method
			// cout<<C::getLength()<<endl;

			// second method
			// use virtual extension
			cout<<getLength()<<endl;
		}
};

int main()
{
	return 0;
}
