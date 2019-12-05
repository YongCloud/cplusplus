/*
 C++ const keyword demonstartion.
 author xingjian
 since 2019/12/05
*/
#include <iostream>
using namespace std;

int main()
{
	/*
	  const marks a primitive variable
	*/
	const int a = 10;
	// error, a is read-only variable
	a = 20;
	int const b = 10;
	// error, b is read-only variable
	b = 20;

	/*
	  const marks a pointer variable.
	  Symmetrical beauty.
	*/
	const char *s = "hello";
	// error, s[0-6] is read-only
	s[0] = 'w';
	// OK
	s = "world";

	char * const t = "hello";
	// OK
	t[0] = 'w';
	// error, t is read-only
	t = "world";

	const char * const pc = "abcdefg";
	// error
	pc[0] = 'x';
	// error
	pc = "xyz";

	return 0;
}
