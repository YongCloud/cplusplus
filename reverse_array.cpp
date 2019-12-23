/*
 * reverse array
 *
 * author xingjian
 * since 2019/12/23
 */
#include <iostream>
using namespace std;

// function definition
void intput_array(int *,int);
void reverse_array(int *,int);
void swap(int *,int *);
void print_array(int *,int);

int main()
{
	int n;
	cout<<"please input a postive integer:"<<endl;
	cin>>n;
	if(n<=0) {
		cout<<"your input is illegal."<<endl;
		return 1;
	}

	int* arr = new int[n];
	if(arr == NULL) {
		cout<<"Failed to apply for memory."<<endl;
		return 2;
	}
	intput_array(arr,n);
	cout<<"original array elements:"<<endl;
	print_array(arr,n);
	reverse_array(arr,n);
	cout<<"reversed array elements:"<<endl;
	print_array(arr,n);

	delete []arr;
	arr = NULL;

	return 0;
}

void intput_array(int *arr,int length)
{
	cout<<"please input "<<length<<" integers:"<<endl;
	for(int i=0; i<length; i++) {
		cin>>arr[i];
	}
}

void reverse_array(int *arr,int length)
{
	for(int i=0; i<length/2; i++) {
		swap(arr+i,arr+length-i-1);
	}
}

// swap two integers
void swap(int *a,int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void print_array(int *arr,int length)
{
	int i = 0;
	for(i=0; i<length-1; i++) {
		cout<<*(arr+i)<<" ";
	}
	cout<<*(arr+i)<<endl;
}
