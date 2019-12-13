/*
 * There is a BUG in Dev-C++ that
 * debug will stop when encounter
 * cout<<endl.
 * We need use cout<<"\n" as replace.
 * fuck!
 *
 * author xingjian
 * since 2019/12/13
 */
#include <iostream>
using namespace std;

// constant of new line
#define NL "\n"

void debug();

int main()
{
	debug();
	return 0;
}

void debug()
{
	int *p;
	cout<<p<<NL;
	p = NULL;
	cout<<p<<NL;
	p = new int;
	cout<<p<<NL;
	delete p;
	// important
	p = NULL;
	cout<<p<<NL;
	delete p;
	cout<<p<<NL;
}

