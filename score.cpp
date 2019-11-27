/*
	9个学生各选了5门课，求总成绩第七名的学生的平均成绩
	author: Xingjian
	since: 2019/10/15
*/
#include <iostream>
using namespace std;

const int ROW = 9;
const int COLUMN = 6;

void sum(int *p[],int row,int column);
void sort(int *p[],int row,int column);
void print_avg(int *p[],int seq,int num);

int main(int argc, char const *argv[])
{
	// length vs index
	int scores[9][6]= {{81,89,99,98,87},{89,90,95,80,90},{91,77,88,95,78},{79,84,95,93,96},
		{95,92,98,99,93},{78,88,85,86,80},{91,85,94,82,88},{90,92,94,90,95},{75,85,87,94,90}
	};
	// define a pointer array, element is a pointer
	int *p[ROW];
	// initialize
	p[0] = &scores[0][0];
	for(int i = 1; i < ROW; i++) {
		p[i] = p[i-1] + COLUMN;
	}

	sum(p,ROW,COLUMN);
	sort(p,ROW,COLUMN);
	print_avg(p,7,COLUMN);

	return 0;
}

void sum(int *p[],int row,int column)
{
	int sum = 0;
	int j = 0;
	for(int i = 0; i < row; i++) {
		sum = 0;
		for(j=0; j < column - 1; j++) {
			sum += *(p[i]+j);
		}
		*(p[i] + j) = sum;
	}
}


// 计算总成绩
void sum(int scores[][COLUMN],int row,int column)
{
	int sum = 0;
	int j = 0;
	for (int i = 0; i < row; i++) {
		sum = 0;
		for (j = 0; j < column - 1; j++) {
			sum += scores[i][j];
		}
		scores[i][j] = sum;
	}
}

void sort(int *p[],int row,int column)
{
	int increment = column - 1;
	int *temp;
	for(int i = 0; i < row - 1; i++) {
		for(int j=0; j < row - i -1; j++) {
			if(*(p[j]+ increment) < *(p[j+1] + increment)) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j+1]  = temp;
			}
		}
	}
}

void print_avg(int *p[],int seq,int num)
{
	cout<< *(p[seq-1] + num - 1) / num<<endl;
}
