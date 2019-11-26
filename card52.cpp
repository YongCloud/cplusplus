/**
	author: Xingjian
	since: 2019/11/26
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define CARD 52
#define NUM 13
#define COLOR 4

// function declaration
void init(int *,int);
void shuffle(int *,int);
void swap(int *,int *);
void print(int *,int);
void print_card(int *,int,const char *[],const char *[]);
void apply(int *,int,int *[]);
void print_apply(int *[],int,const char *[],const char *[]);
string is_brother(int *[],int);
int main(int argc, char const *argv[])
{
	// 4 colors
	const char *suit[COLOR] = {"Hearts","Diamonds","Clubs","Spades"};
	// 13 faces
	const char *face[NUM] = {"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	// 52 cards
	int card[CARD];

	init(card,CARD);
	shuffle(card,CARD);
	print(card,CARD);
	print_card(card,CARD,suit,face);

	int *q[5];
	apply(card,5,q);
	print_apply(q,5,suit,face);
	cout<<"is brother?"<<is_brother(q,5)<<endl;

	return 0;
}

// initialize
void init(int *p,int n)
{
	for(int i = 0; i< n; i++) {
		*(p+i) = i;
	}
}

// shuffle
void shuffle(int *p,int n)
{
	// initialize random generator seed
	srand(time(NULL));
	for(int i = 0; i< n; i++) {
		// generate a random integer between 0 and n
		int r = rand()%n;
		swap(p+i,p+r);
	}
}

// swap two integer
void swap(int *a,int *b)
{
	/*
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	*/
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// apply card
void apply(int *p,int n,int *q[])
{
	for(int i = 0; i< n; i++) {
		*(q+i) = p+i;
	}
}

// print array element
void print(int *p,int n)
{
	for(int i = 0; i< n; i++) {
		cout<<setw(3)<<*(p+i)<<" ";
		if((i+1) % NUM == 0) {
			cout<<endl;
		}
	}
	cout<<endl;
}

// print array card
void print_card(int *p,int n,const char *suit[],const char *face[])
{
	for(int i = 0; i<n; i++) {
		int color = *(p+i) / NUM;
		int num = *(p+i) % NUM;
		cout<<setw(7)<<suit[color]<<"-"<<face[num]<<" ";
		if((i+1) % 4 == 0) {
			cout<<endl;
		}
	}
	cout<<endl;
}

void print_apply(int *q[],int n,const char *suit[],const char *face[])
{
	cout<<"applied "<<n<<" cards"<<endl;
	for(int i = 0; i< n; i++) {
		/*
		int color = *q[i] / NUM;
		q[i] = *(q+i)
		*/
		int color = *(*(q+i)) / NUM;
		int num = *(*(q+i)) % NUM;
		cout<<suit[color]<<"-"<<face[num]<<" ";
	}
	cout<<endl;
}

string is_brother(int *q[],int n)
{
	for(int i=0; i<n; i++) {
		int a = *(*(q+i)) % NUM;
		for(int j=i+1; j<n; j++) {
			int b = *(*(q+j)) % NUM;
			if(a == b) {
				return "true";
			}
		}
	}
	return "false";
}
