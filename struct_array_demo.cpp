/*
 struct array demonstration.
 author xingjian
 since 2019/12/06
*/
#include <iostream>
using namespace std;

// constant
#define N 5

struct Grade {
	int num;
	int english;
	int math;
	int physics;
	int sum;
	int NO;
};

// function declaration
void input(struct Grade *);
void sum(struct Grade *);
void sort(struct Grade *);
void print(struct Grade *);

int main(int argc, char const *argv[]) {
	struct Grade arr[N];
	input(arr);
	sum(arr);
	sort(arr);
	print(arr);
	return 0;
}

void input(struct Grade *p) {
	for(int i = 0; i<N; i++) {
		cout<<"please input num and english math physics grade:"<<endl;
		cin>>(p+i)->num>>(p+i)->english>>(p+i)->math>>(p+i)->physics;
	}
}

void sum(struct Grade *p) {
	int sum = 0;
	for(int i = 0; i<N; i++) {
		sum = (p+i)->english + (p+i)->math + (p+i)->physics;
		(p+i)->sum = sum;
		sum = 0;
	}
}

void sort(struct Grade *p) {
	struct Grade temp;
	/*
	  bubble sort
	*/
	// count of turn
	for(int i = 0; i<N-1; i++) {
		// every turn
		for(int j = 0; j<N-1-i; j++) {
			// compare
			if(p[j].sum < p[j+1].sum) {
				// swap
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	// fill NO field
	for (int i = 0; i < N; i++) {
		(p+i)->NO = i+1;
	}
}

void print(struct Grade *p) {
	cout<<"num\t"<<"english\t"<<"math\t"<<"physics\t"<<"sum\t"<<"NO"<<endl;
	for (int i = 0; i < N; i++) {
		cout<<(p+i)->num<<"\t"<<(p+i)->english<<"\t"<<(p+i)->math<<"\t"
		    <<(p+i)->physics<<"\t"<<(p+i)->sum<<"\t"<<(p+i)->NO<<endl;
	}
}
