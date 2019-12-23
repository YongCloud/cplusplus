/*
 * count factor
 *
 * author xingjian
 * since 2019/12/23
 */
#include <iostream>
using namespace std;

int count_factor(int);
int count(int,int);

int main()
{
	int start = 100;
	int end = 200;
	cout<<count(100,200)<<endl;

	return 0;
}

int count_factor(int n)
{
	int factor = 0;
	for(int i=1; i<=n; i++) {
		if(n%i == 0) {
			factor++;
		}
	}
	return factor;
}

int count(int start,int end)
{
	int sum = 0;
	int factor = 0;
	for(int i=start; i<=end; i++) {
		factor = count_factor(i);
		if(factor%2 != 0) {
			sum++;
		}
	}
	return sum;
}
