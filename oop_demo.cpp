/*
 OOP demonstration.
 encapsulation
 extend
 polymon...
 author xingjian
 since 2019/12/07
*/
#include <iostream>
using namespace std;

// struct
/*
struct Student {
	int num;
	char name[20];
};
*/

class Student {
	private:
		int num;
		char *name;

	public:
		// constructor
		Student(){
		}
		
		Student(int n,char *na) {
			num = n;
			name = na;
		}

		void setNum(int n) {
			if(n < 0) {
				return;
			}
			num = n;
		}

		int getNum() {
			return num;
		}

		void setName(char *na) {
			name = na;
		}

		char * getName() {
			return name;
		}
};

int main()
{
	/*
	struct Student stu;
	stu.num = 19213210;
	stu.name = "XXX";
	stu.num = 19213211;
	*/
	char name[20] = "Jack";
	
	// class object
	Student stu;
	stu.setNum(1111);
	stu.setName(name);
	cout<<stu.getNum()<<" "<<stu.getName()<<endl;

	return 0;
}
