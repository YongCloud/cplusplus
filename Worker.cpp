/*
 Worker class
 author xingjian
 since 2019/12/11
*/
#include <iostream>
#include <cstring>
using namespace std;

// constant of new line
#define NL "\n"

const int length = 9;

class Worker {
	private:
		int id;
		char *name;
		float wage;
		char level;
	public:
		Worker() {
			cout<<"constructor with no parameter"<<NL;
			id = 0;
			name = NULL;
			wage = 0;
			level = '\0';
		}

		Worker(int id,const char *name,float wage,char level);

		Worker(const Worker &other);

		~Worker() {
			delete []name;
			name = NULL;
			cout<<"destructor called"<<NL;
		}

		void list();
};

Worker::Worker(int id,const char *name,float wage,char level)
{
	cout<<"constructor with parameters"<<NL;
	this->id = id;
	this->name = new char[length];
	if(this->name != NULL) {
		strcpy(this->name,name);
	}
	this->wage = wage>=200?wage:200;
	this->level = level;
}

Worker::Worker(const Worker &other)
{
	cout<<"copy constructor"<<NL;
	this->id = other.id;
	this->name = new char[length];
	if(this->name != NULL) {
		strcpy(this->name,other.name);
	}
	this->wage = other.wage;
	this->level = other.level;
}

void Worker::list()
{
	cout<<id<<" ";
	if(name != NULL) {
		cout<<name<<" ";
	}
	cout<<wage<<" "<<level<<NL;
}

int main()
{
	// create object
	Worker zhao;
	Worker qian(1,"qian",0,'\0');
	Worker sun(2,"sun",50,'C');
	Worker li = qian;
	// use oject
	zhao.list();
	qian.list();
	sun.list();
	li.list();
	// destroy oject
	return 0;
}
