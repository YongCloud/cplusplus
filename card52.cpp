/*
 author: Xingjian
 since: 2019/11/26
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// constant declaration
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
bool have_one_pairs(int *[],int);
int pairs(int *[],int);

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
	cout<<"shuffled card index:"<<endl;
	print(card,CARD);
	cout<<"shuffled card:"<<endl;
	print_card(card,CARD,suit,face);

	int *q[5];
	apply(card,5,q);
	print_apply(q,5,suit,face);
	cout<<"these cards have one pairs? ";
	if(have_one_pairs(q,5)) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

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
	// take care of a=b, otherwise *a will be 0
	if(a == b) {
		return;
	}
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
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

// print applied card
void print_apply(int *q[],int n,const char *suit[],const char *face[])
{
	cout<<"applied "<<n<<" cards:"<<endl;
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

// these cards have one pairs?
bool have_one_pairs(int *q[],int n)
{
	int pair = pairs(q,n);
	if(1 == pair) {
		return true;
	}
	return false;
}

// get pairs int the card
int pairs(int *q[],int n)
{
	int pair = 0;
	for(int i=0; i<n; i++) {
		int the = *(*(q+i)) % NUM;
		for(int j=i+1; j<n; j++) {
			int that = *(*(q+j)) % NUM;
			if(the == that) {
				pair++;
			}
		}
	}
	return pair;
}
