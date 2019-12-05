/*
 C++ new and delete keywords demonstration.
 author xingjian
 since 2019/12/03
*/
#include <iostream>
using namespace std;

int main()
{
	// apply for int
	int *p = new int(5);
	if(p == NULL) {
		cout<<"Failed to apply for memory."<<endl;
	} else {
		cout<<*p<<endl;
		delete p;
		// and now, p is not NULL
		cout<<*p<<endl;
		// so we must let p be NULL
		p = NULL;
	}

	// apply for a block memory
	int *arr = new int[1024];
	if(arr == NULL) {
		cout<<"Failed to apply for memory."<<endl;
	} else {
		delete []arr;
		// we must let p be NULL
		arr = NULL;
	}

	return 0;
}
