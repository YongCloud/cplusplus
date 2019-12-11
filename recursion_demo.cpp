/*
 recursion demonstration
 author xingjian
 since 2019/12/10
*/
#include <iostream>
using namespace std;

const int thresh_hold = 7654321;

int f(int);

int main() {
	for(int i = 1; i < 100; i++) {
		int result = f(i);
		if(result > thresh_hold) {
			cout<<"item "<<i<<" with value "<<result<<endl;
			break;
		}
	}
	return 0;
}

/// f(1)=1,f(2)=4,f(n)=3*f(n-1) - f(n-2)
int f(int n) {
	if(n == 1) {
		return 1;
	}
	if(n == 2) {
		return 4;
	}
	return 3 * f(n-1) - f(n - 2);
}
