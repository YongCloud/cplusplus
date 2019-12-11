/*
 function with default parameter
 author xingjian
 since 2019/12/08
*/
#include <iostream>
using namespace std;

// function declaration
int sum(int,int b = 20);

int main() {
	cout<<sum(10)<<endl;
	cout<<sum(10,90)<<endl;
	return 0;
}

int sum(int a,int b) {
	return a+b;
}
