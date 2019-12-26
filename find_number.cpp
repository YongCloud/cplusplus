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
	int a,b,high,k;
	for(int i=1; i<=9; i++) { // 9
		a = i*i*i;
		high = pow(N-a,1.0/3) + 1;
		for(int j=0; j<=high; j++) { // 11
			b = N - a - j*j*j;
			k =  pow(b,1.0/3);
			if(b == k*k*k) {
				cout<<(i*100 + j*10 + k)<<endl;
			}
		}
	}
	return 0;
}
