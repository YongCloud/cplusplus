/*
 linkedlist demonstration.
 @author xinjian
 @since 2019/12/04
*/
#include <iostream>
#include <cstdlib>
using namespace std;

// constant
#define MAX_LENGTH 30
const char *msg = "Failed to apply for memory.";

// node definition
typedef struct Node {
	int no;
	char name[MAX_LENGTH];

	// pointer to next Node
	Node *next;
} Node;

// function declaration
void input_stu_info(Node *,int);
void delete_same(Node *,Node *);
void print_stu_info(Node *);
bool exist(Node *,int);

int main() {
	int a,b;
	// head node
	Node *h1,*h2;
	// initialize head node
	h1 = (Node *)calloc(1,sizeof(Node));
	if(h1 == NULL) {
		cout<<msg<<endl;
		return 1;
	}
	h2 = (Node *)calloc(1,sizeof(Node));
	if(h2 == NULL) {
		cout<<msg<<endl;
		return 1;
	}

	cout<<"how many students in linked list a?"<<endl;
	cin>>a;
	input_stu_info(h1,a);
	cout<<"students information in linkedlist a:"<<endl;
	print_stu_info(h1);

	cout<<"how many students in linked list b?"<<endl;
	cin>>b;
	input_stu_info(h2,b);
	cout<<"students information in linkedlist b:"<<endl;
	print_stu_info(h2);

	delete_same(h1,h2);
	cout<<"students information in linkedlist a after deleting:"<<endl;
	print_stu_info(h1);

	return 0;
}

// input students information
void input_stu_info(Node *h,int n) {
	Node *p = h;
	for(int i=0; i<n; i++) {
		Node *node = (Node *)calloc(1,sizeof(Node));
		if(node == NULL) {
			cout<<msg<<endl;
			break;
		}
		cout<<"please input NO. and name:"<<endl;
		cin>>node->no>>node->name;
		p->next = node;
		p = node;
	}
}

// remove student information from linkedlist h1,
// when a same student NO. in linkedlis h2.
void delete_same(Node *h1,Node *h2) {
	Node *p = h1;
	Node *q = p->next;
	while(q) {
		if(exist(h2,q->no)) {
			// delete node
			p->next = q->next;
			free(q);
			q = NULL;
			q = p->next;
		} else {
			p = q;
			q = p->next;
		}
	}
}

bool exist(Node *h,int no) {
	Node *p = h;
	while(p->next) {
		p = p->next;
		if(no == p->no) {
			return true;
		}
	}
	return false;
}

// students information in the linkedlist
void print_stu_info(Node *h) {
	Node *p = h;
	cout<<"NO.\t"<<"Name"<<endl;
	while(p->next) {
		p = p->next;
		cout<<p->no<<"\t"<<p->name<<endl;
	}
}

