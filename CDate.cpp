/*
 OOP demonstartion.
 author xingjian
 since 2019/12/08
*/
#include <iostream>
using namespace std;

// class definition
class CDate {
	private:
		int day;
		int month;
		int year;

	public:
		// constructor with no parameter
		Cdate() {
		}

		Cdate(int d,int m,int y) {
			day=d;
			month=m;
			year=y;
		}

		void setDay(int d) {
			if(d <= 0 && d > 31) {
				return;
			}
			day=d;
		}

		int getDay() {
			return day;
		}

		void setMonth(int m) {
			if(m <= 0 && m>12) {
				return;
			}
			month=m;
		}

		int getMonth() {
			return month;
		}

		void setYear(int y) {
			if(y<0) {
				return;
			}
			year=y;
		}

		int getYear() {
			return year;
		}


		void addOneDay() {
			int temp = day + 1;
			switch(month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
					if(temp > 31) {
						day = 1;
						month++;
					} else {
						day = temp;
					}
					break;
				case 12:
					if(temp > 31) {
						day = 1;
						month = 1;
						year++;
					} else {
						day = temp;
					}
					break;

				case 2:
					if(isLeapYear()) {
						if(temp>28) {
							day = 1;
							month++;
						} else {
							day = temp;
						}
					} else {
						if(temp>29) {
							day = 1;
							month++;
						} else {
							day = temp;
						}
					}
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					if(temp > 30) {
						day = 1;
						month++;
					} else {
						day = temp;
					}
					break;
			}
		}

		bool isLeapYear() {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				return true;
			}
			return false;
		}

		void print() {
			cout<<day<<"/"<<month<<"/"<<year<<endl;
		}
};

int main()
{
	int d,m,y;
	cout<<"please input year month day"<<endl;
	cin>>y>>m>>d;
	CDate today;
	today.setDay(d);
	today.setMonth(m);
	today.setYear(y);
	today.addOneDay();
	cout<<"the day after today:"<<endl;
	today.print();

	return 0;
}

