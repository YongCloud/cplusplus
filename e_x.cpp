/*
 calculate e to the power of x.
 author xingjian
 since 2019/12/02
*/
#include <iostream>
using namespace std;

// constant
#define THRESH_HOLD 1.0e-5

// function declaration
double e_x(int);
double item(int,int);
int power(int,int);
int factor(int);

int main()
{
	int x;
	//printf("%lf\n",THRESH_HOLD);
	cout<<"please input a integer:"<<endl;
	cin>>x;
	cout<<"result: "<<e_x(x)<<endl;
	return 0;
}

// return e to the power of x
double e_x(int x)
{
	double sum = 0.0;
	int i = 0;
	double entry = item(x,i);
	while(entry >= THRESH_HOLD) {
		sum += entry;

		i++;
		entry = item(x,i);
	}
	return sum;
}

// return power(x,n) / factor(n)
double item(int x,int n)
{
	return (double)power(x,n) / factor(n);
}

// return power(x,n)
int power(int x,int n)
{
	int r = 1;
	for(int i = 0; i < n; i++) {
		r *= x;
	}
	return r;
}

// return factor of n
int factor(int n)
{
	if(0 == n) {
		return 1;
	}
	int r = 1;
	for(int i = 1; i <= n; i++) {
		// r = r * i;
		r *= i;
	}
	return r;
}

