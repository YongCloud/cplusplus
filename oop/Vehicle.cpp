/*
 * Inheritance demonstration with C++.
 * This demo shows Multiple Inheritance
 * and Virtual Base Class
 *
 * author xingjian
 * since 2019/12/17
 */
#include <iostream>
using namespace std;

class Vehicle {
	private:
		int speed;
		int weight;
	public:
		Vehicle() {
			this->speed = 0;
			this->weight = 0;
		}

		Vehicle(int speed,int weight) {
			this->speed = speed;
			this->weight = weight;
		}

		int getSpeed() {
			return this->speed;
		}

		int getWeight() {
			return this->weight;
		}

		void setSpeed(int speed) {
			this->speed = speed;
		}

		void setWeight(int weight) {
			this->weight = weight;
		}

		void print() {
			cout<<"speed: "<<speed<<" weight: "<<weight<<endl;
		}
} ;

class Bicycle:virtual public Vehicle {
	private:
		int height;
	public:
		Bicycle():Vehicle(0,0) {
			this->height = 0;
		}

		Bicycle(int speed,int weight,int height):Vehicle(speed,weight) {
			this->height = height;
		}

		int getHeight() {
			return this->height;
		}

		void setHeight(int height) {
			this->height = height;
		}

		void print() {
			cout<<"speed: "<<getSpeed()<<
			    " weight: "<<getWeight()<<
			    " height: "<<height<<endl;
		}
};

class Car:virtual public Vehicle {
	private:
		int seatnum;
	public:
		Car():Vehicle(0,0) {
			this->seatnum = 0;
		}

		Car(int speed,int weight,int seatnum):Vehicle(speed,weight) {
			this->seatnum = seatnum;
		}

		int getSeatnum() {
			return this->seatnum;
		}

		void setSeatnum(int seatnum) {
			this->seatnum = seatnum;
		}

		void print() {
			cout<<"speed: "<<getSpeed()<<
			    " weight: "<<getWeight()<<
			    " seatnum: "<<seatnum<<endl;
		}
};

class Motocycle:public Bicycle,public Car {
	public:
		Motocycle():Bicycle(0,0,0),Car(0,0,0) {
		}

		Motocycle(int speed,int weight,int height,int seatnum):
			Vehicle(speed,weight),// why speed and weight is 0 without this line?
			Bicycle(speed,weight,height),Car(speed,weight,seatnum) {
		}

		void print() {
			cout<<"speed: "<<getSpeed()<<
			    " weight: "<<getWeight()<<
			    " height: "<<getHeight()<<
			    " seatnum: "<<getSeatnum()<<endl;
		}
};

int main()
{
	Bicycle* bi = new Bicycle(20,30,1);
	bi->print();
	Motocycle* moto = new Motocycle(60,240,1,2);
	moto->print();

	delete bi;
	bi = NULL;
	delete moto;
	moto = NULL;

	return 0;
}
