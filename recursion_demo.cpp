/*
 recursion demonstration.
 there is a function definition as following:
 f(1)=1,
 f(2)=4,
 f(n)=3*f(n-1) - f(n-2)
 please calculate n where f(n) just more than 7654321.
 so how should we solve this problem?
 author xingjian
 since 2019/12/10
*/
#include <iostream>
#include <vector>
using namespace std;

const int thresh_hold = 7654321;

int fun_iter(int);
int fun_recur(int);
int fun_dp(int);

int main()
{
	// pointer to function
	int (*p)(int) = fun_dp;
	for(int i = 1; i < 100; i++) {
		int result = p(i);
		if(result > thresh_hold) {
			cout<<"item "<<i<<" with value "<<result<<endl;
			break;
		}
	}
	return 0;
}

// solve with iteration
int fun_iter(int n)
{
	if(n == 1) {
		return 1;
	}
	if(n == 2) {
		return 4;
	}
	int a = 1;
	int b = 4;
	int f = 0;
	for(int i = 3; i <= n; i++) {
		f = 3 * b - a;
		a = b;
		b = f;
	}
	return f;
}

// solve with recursion
int fun_recur(int n)
{
	if(n == 1) {
		return 1;
	}
	if(n == 2) {
		return 4;
	}
	return 3 * fun_recur(n-1) - fun_recur(n - 2);
}

/*
  solve with recursion and dynamic programming
*/
vector<int> vec;
int fun_dp(int n)
{
	// return cached value
	if(n <= vec.size()) {
		return vec[n-1];
	}
	// calculate and put result into cache
	int ret = 0;
	if(n == 1) {
		ret = 1;
	} else if(n == 2) {
		ret = 4;
	} else {
		ret = 3 * fun_dp(n-1) - fun_dp(n-2);
	}
	vec.push_back(ret);
	return ret;
}
