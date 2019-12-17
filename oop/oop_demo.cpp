/*
 OOP demonstration.

 key concepts:
 POP(Procedure Oriented Programming) --> 面向过程程序设计
 OOP(Object Oriented Programming) --> 面向对象程序设计

 three features of OOP:
 Encapsulation --> 封装（安全、规范、可控、信息隐藏）
 Inheritance --> 继承（代码复用）
 Polymorphism --> 多态（动态、智能、动感）

 author xingjian
 since 2019/12/07
*/
#include <iostream>
#include <cstring>
using namespace std;

// structure definition
struct Stu {
	int num;
	char name[20];
};

// class definition
class Student {
	private:
		int num;
		const char *name;

	public:
		// special functions
		Student() {
			cout<<"constructor with no parameter"<<endl;
		}

		Student(int n,const char *na) {
			cout<<"constructor with parameter"<<endl;
			num = n;
			name = na;
		}

		~Student() {
			cout<<"destructor called"<<endl;
		}

		// other functions
		void setNum(int n) {
			if(n < 0) {
				return;
			}
			num = n;
		}

		int getNum() {
			return num;
		}

		void setName(const char *na) {
			name = na;
		}

		const char *getName() {
			return name;
		}

		void print() {
			cout<<num<<" "<<name<<endl;
		}
};

int main()
{
	// structure usage
	struct Stu stu;
	stu.num = 19213210;
	strcpy(stu.name,"Steve Yang");
	cout<<stu.num<<" "<<stu.name<<endl;

	// class v.s object
	Student a;
	a.setNum(1111);
	a.setName("Jack");
	a.print();

	Student b(1112,"Tom");
	b.print();

	Student *c = new Student(1113,"Merry");
	c->print();
	// important
	delete c;

	return 0;
}
