/*
 linkedlist demonstration.
 author xingjian
 since 2019/12/04
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
void input_stu_info(Node * const);
void delete_same(Node * const,Node * const);
void print_stu_info(Node * const);
bool exist(Node * const,int);

int main()
{
	// declare head node and initialize it
	Node * const ha = (Node *)calloc(1,sizeof(Node));
	if(ha == NULL) {
		cout<<msg<<endl;
		return 1;
	}
	Node * const hb = (Node *)calloc(1,sizeof(Node));
	if(hb == NULL) {
		cout<<msg<<endl;
		return 1;
	}

	cout<<"how many students in linkedlist a?"<<endl;
	cin>>ha->no;
	input_stu_info(ha);
	cout<<"students information in linkedlist a:"<<endl;
	print_stu_info(ha);

	cout<<"how many students in linkedlist b?"<<endl;
	cin>>hb->no;
	input_stu_info(hb);
	cout<<"students information in linkedlist b:"<<endl;
	print_stu_info(hb);

	delete_same(ha,hb);
	cout<<"students information in linkedlist a after deleting:"<<endl;
	print_stu_info(ha);

	return 0;
}

// input students information
void input_stu_info(Node * const h)
{
	Node *p = h;
	for(int i=0; i<h->no; i++) {
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

// remove student information from linkedlist ha,
// when a same student NO. in linkedlis hb.
void delete_same(Node * const ha,Node * const hb)
{
	Node *p = ha;
	Node *q = p->next;
	while(q) {
		if(exist(hb,q->no)) {
			// delete node
			p->next = q->next;
			free(q);
			q = NULL;
			q = p->next;
			ha->no--;
		} else {
			p = q;
			q = p->next;
		}
	}
}

bool exist(Node * const h,int no)
{
	Node *p = h;
	while(p->next) {
		p = p->next;
		if(no == p->no) {
			return true;
		}
	}
	return false;
}

// print students information in the linkedlist
void print_stu_info(Node * const h)
{
	Node *p = h;
	cout<<"NO.\t"<<"Name"<<endl;
	while(p->next) {
		p = p->next;
		cout<<p->no<<"\t"<<p->name<<endl;
	}
}

