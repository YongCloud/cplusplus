/*
 worker class
 author xingjian
 since 2019/12/11
*/
#include <iostream>
#include <cstring>
using namespace std;

const int length = 9;

class worker
{
	private:
		int id;
		char *name;
		float wage;
		char level;
	public:
		worker() {
			cout<<"constructor with no parameter"<<endl;
			id = 0;
			name = NULL;
			wage = 0;
			level = '\0';
		}

		worker(int id,const char *name,float wage,char level) {
			cout<<"constructor with parameters"<<endl;
			this->id = id;
			name = new char[length];
			if(name != NULL) {
				strcpy(this->name,name);
			}
			this->wage = wage;
			this->level = level;
		}

		worker(worker &other) {
			cout<<"copy constructor"<<endl;
			this->id = other.id;
			name = new char[length];
			if(name != NULL) {
				strcpy(this->name,other.name);
			}
			this->wage = other.wage;
			this->level = other.level;
		}

		~worker() {
			cout<<"destructor"<<endl;
			delete []name;
		}


};

int main()
{
	return 0;
}
