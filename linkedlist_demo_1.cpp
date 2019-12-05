/*
 linkedlist demonstration.
 use new keyword and remove typedef keyword.
 @author xingjian
 @since 2019/12/04
*/
#include <iostream>
using namespace std;

// constant
#define MAX_LENGTH 30
const char *msg = "Failed to apply for memory.";

// node definition
struct Node {
	int no;
	// string ends with '\0'
	char name[MAX_LENGTH];
	// pointer to next Node
	struct Node *next;
};

// function declaration
void input_stu_info(struct Node *,int);
void delete_same(struct Node *,struct Node *);
void print_stu_info(struct Node *);
bool exist(struct Node *,int);

int main() {
	int a,b;
	// head node
	Node *h1,*h2;
	// initialize head node
	h1 = new struct Node;
	if(h1 == NULL) {
		cout<<msg<<endl;
		return 1;
	}
	h2 = new struct Node;
	if(h2 == NULL) {
		cout<<msg<<endl;
		return 1;
	}

	cout<<"how many students in linkedlist a?"<<endl;
	cin>>a;
	input_stu_info(h1,a);
	cout<<"students information in linkedlist a:"<<endl;
	print_stu_info(h1);

	cout<<"how many students in linkedlist b?"<<endl;
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
void input_stu_info(struct Node *h,int n) {
	struct Node *p = h;
	for(int i=0; i<n; i++) {
		struct Node *node = new struct Node;
		if(node == NULL) {
			cout<<msg<<endl;
			break;
		}
		cout<<"please input NO. and name:"<<endl;
		cin>>node->no>>node->name;
		// cout<<node->next<<endl;
		// when allocate memory with new keyword,
		// we must let node->next be NULL
		node->next = NULL;
		p->next = node;
		p = node;
	}
}

// remove student information from linkedlist h1,
// when a same student NO. in linkedlis h2.
void delete_same(struct Node *h1,struct Node *h2) {
	struct Node *p = h1;
	struct Node *q = p->next;
	while(q) {
		if(exist(h2,q->no)) {
			// delete node
			p->next = q->next;
			delete q;
			q = NULL;
			q = p->next;
		} else {
			p = q;
			q = p->next;
		}
	}
}

bool exist(struct Node *h,int no) {
	struct Node *p = h;
	while(p->next) {
		p = p->next;
		if(no == p->no) {
			return true;
		}
	}
	return false;
}

// students information in the linkedlist
void print_stu_info(struct Node *h) {
	struct Node *p = h;
	cout<<"NO.\t"<<"Name"<<endl;
	while(p->next) {
		p = p->next;
		cout<<p->no<<"\t"<<p->name<<endl;
	}
}

