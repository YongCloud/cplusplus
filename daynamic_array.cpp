/*
 * dynamic array?
 * compiled with G++
 *
 * author xingjian
 * since 2019/12/26
 */
#include <iostream>
using namespace std;

int main()
{
	int m;
	cout<<"please input a integer:"<<endl;
	cin>>m;
	// and now, we can define array with variable size,
	// maybe operator [] has been overloaded by G++ compiler
	int a[m];
	cout<<"please input "<<m<<" integers:"<<endl;
	for(int i=0; i<m; i++) {
		cin>>a[i];
	}

	cout<<"array elements:"<<endl;
	for(int i=0; i<m; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}
