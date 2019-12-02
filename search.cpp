/*
 在一个5*5的矩阵中，找出最大数与中间位置上的数交换，
 找出最小的四个数与四角上的数交换（左小右大，上小下大）。
 author: Xingjian, Nanjing University C++ teacher
 since: 2019/10/23
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int ROW=5;
const int COL=5;
const int SIZE=5;
void search(int (*)[COL], int , int **,int);
void sort(int **,int);
void exchange(int (*)[COL], int , int **,int);
void swap(int *,int*);
void input(int (*)[COL], int );
void output(int (*)[COL], int );
void output(int **, int);

main()
{
	int a[ROW][COL];
	int *arr[SIZE];

	input(a,ROW);
	cout<<"array original:"<<endl;
	output(a,ROW);
	search(a,ROW, arr,SIZE);

	output(arr,SIZE);
	sort(arr,SIZE-1);
	output(arr,SIZE);

	exchange(a,ROW, arr,SIZE);
	cout<<"array exchanged:"<<endl;
	output(a,ROW);

	return 0;
}

// get the max element in the array
int max(int *a,int n)
{
	int max = *a;
	for(int i = 0; i < n; i++) {
		if(max < *(a+i)) {
			max = *(a+i);
		}
	}
	return max;
}

void search(int (*p)[COL], int line, int **arr,int size)
{
	int i;
	int j;
	int max;
	/*
		9 8 7 0 2 3    arr = {9,8,7,0,2,9}
	*/
	// for (i=0,arr[4]=&a[0][0]; i<4; i++)
	// arr[4]=&a[0][0];for (i=0; i<4; i++)
	for (i=0,arr[size-1]=*p; i<size-1; i++) {
		// arr[0] = &a[0][0]
		arr[i]=*p+i;
		if (*arr[size-1]<*(*p+i)) {
			arr[size-1]=*p+i;
		}
	}

	// for(i = 4;i<25;i++)
	for (i=size-1; i<line*COL; i++) {
		// get max
		if (*arr[size-1]<*(*p+i)) {
			arr[size-1]=*p+i;
		}

		// get the min 4th number
		int flag=1;
		// max=0; for (j=0;j<4; j++)
		for (j=0,max=0; j<size-1; j++) {
			if (*arr[j]>*(*p+i)) {
				flag=0;
			}
			if (*arr[max]<*arr[j]) {
				max=j;
			}
		}
		if (flag==0) {
			arr[max]=*p+i;
		}
	}
}

void sort(int **arr,int size)
{
	int i,j;
	int *temp;

	for (i=1; i<size; i++) {
		for (j=0; j<size-1; j++) {
			if (*arr[j]>*arr[j+1]) {
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
/*
void exchange(int (*p)[COL], int line, int **arr,int size)
{
	if ((arr[size-1]==*p||arr[size-1]==*p+COL-1
		||arr[size-1]==*p+(line-1)*COL||arr[size-1]==*p+line*COL-1)&&
		(arr[0]==*p+(line/2)*COL+COL/2||arr[1]==*p+(line/2)*COL+COL/2
		||arr[2]==*p+(line/2)*COL+COL/2||arr[3]==*p+(line/2)*COL+COL/2))
	{
		swap(arr[0],*p);
		swap(arr[1],*p+COL-1);
		swap(arr[2],*p+(line-1)*COL);
		swap(arr[3],*p+line*COL-1);
	}
	else if (arr[size-1]==*p||arr[size-1]==*p+COL-1
		||arr[size-1]==*p+(line-1)*COL||arr[size-1]==*p+line*COL-1)
	{
		swap(*p+(line/2)*COL+COL/2,arr[size-1]);
		swap(arr[0],*p);
		swap(arr[1],*p+COL-1);
		swap(arr[2],*p+(line-1)*COL);
		swap(arr[3],*p+line*COL-1);
	}
	else
	{
		swap(arr[0],*p);
		swap(arr[1],*p+COL-1);
		swap(arr[2],*p+(line-1)*COL);
		swap(arr[3],*p+line*COL-1);
		swap(*p+(line/2)*COL+COL/2,arr[size-1]);
	}
}
*/
void exchange(int (*p)[COL], int line, int **arr,int size)
{
	int temp=*arr[size-1];

	swap(arr[0],*p);
	swap(arr[1],*p+COL-1);
	swap(arr[2],*p+(line-1)*COL);
	swap(arr[3],*p+line*COL-1);

	int flag=1;
	for (int i=0; i<size-1; i++) {
		if (*arr[i]==temp) {
			flag=0;
			swap(*p+(line/2)*COL+COL/2,arr[i]);
		}
	}
	if (flag==1) {
		swap(*p+(line/2)*COL+COL/2,arr[size-1]);
	}
}

void swap(int *p,int*p1)
{
	int temp;

	temp=*p;
	*p=*p1;
	*p1=temp;
}


void input(int (*p)[COL], int  line)
{
	int i,j;

	for (i=0; i<line; i++) {
		cout<<"please input "<<COL<<" element"<<endl;
		for (j=0; j<COL; j++) {
			cin>>*(*(p+i)+j);
		}
	}
}
void output(int (*p)[COL], int line)
{
	int i,j;

	for (i=0; i<line; i++) {
		for (j=0; j<COL; j++) {
			cout<<setw(8)<<*(*(p+i)+j);
		}
		cout<<endl;
	}
}

void output(int ** arr, int size)
{
	cout<<size<<" elements"<<endl;
	for (int i=0; i<size; i++) {
		cout<<setw(8)<<*arr[i];
	}
	cout<<endl;
}
