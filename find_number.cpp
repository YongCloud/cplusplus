/*
 * Find all three digits where the sum of the cubes of
 * all three digits equal to 1099.
 *
 * author xingjian
 * since 2019/12/26
 */

#include <iostream>
#include <math.h>
using namespace std;

#define N 1099

int main()
{
	int a,b,k;
	for(int i=1; i<=9; i++) { // 9
		a = i*i*i;
		for(int j=0; j<=9; j++) { // 10
			b = N - a - j*j*j;
			// cout<<pow(729,1.0/3)<<endl; --> 9
			// k = pow(729,1.0/3);  --> 8
			// Oh my God, what happened?
			k = pow(b,1.0/3);
			if(b == k*k*k) {
				cout<<(i*100 + j*10 + k)<<"\n";
			}
			k++;
			if(b == k*k*k) {
				cout<<(i*100 + j*10 + k)<<"\n";
			}
		}
	}

	return 0;
}
