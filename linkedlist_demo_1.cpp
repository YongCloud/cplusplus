/*
 linkedlist demonstration.
 use new keyword and remove typedef keyword.
 author xingjian
 since 2019/12/04
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
void input_stu_info(struct Node * const,int);
void delete_same(struct Node * const,struct Node * const);
void print_stu_info(struct Node * const);
bool exist(struct Node *const,int);

int main()
{
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
void input_stu_info(struct Node * const h,int n)
{
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

// remove student information from linkedlist ha,
// when a same student NO. in linkedlis hb.
void delete_same(struct Node * const ha,struct Node *hb)
{
	struct Node *p = ha;
	struct Node *q = p->next;
	while(q) {
		if(exist(hb,q->no)) {
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

bool exist(struct Node * const h,int no)
{
	struct Node *p = h;
	while(p->next) {
		p = p->next;
		if(no == p->no) {
			return true;
		}
	}
	return false;
}

// print students information in the linkedlist
void print_stu_info(struct Node * const h)
{
	struct Node *p = h;
	cout<<"NO.\t"<<"Name"<<endl;
	while(p->next) {
		p = p->next;
		cout<<p->no<<"\t"<<p->name<<endl;
	}
}

