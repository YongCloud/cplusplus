/*
 * Abstract class with C++
 *
 * author xingjian
 * since 2019/12/21
 */
#include <iostream>
using namespace std;

#define PI 3.1415926535

// abstract class
class Shape {
	public:
		virtual float getArea() = 0;

		virtual float getPerim() = 0;
};

class Circle:public Shape {
	private:
		float radius;
	public:
		Circle() {
			this->radius = 0;
		}

		Circle(float radius) {
			this->radius = radius;
		}

		float getRadius() {
			return this->radius;
		}

		float getArea() {
			return radius * radius * PI;
		}

		float getPerim() {
			return 2 * PI * radius;
		}
};

class InnerSquare:public Circle {
	public:
		InnerSquare():Circle(0) {
		}

		InnerSquare(float radius):Circle(radius) {
		}

		float getArea() {
			float radius = this->getRadius();
			return 2 * radius * radius;
		}

		float getPerim() {
			float radius = this->getRadius();
			return 4 * 1.414 * radius;
		}
};

class OuterSquare:public Circle {
	public:
		OuterSquare():Circle(0) {
		}

		OuterSquare(float radius):Circle(radius) {
		}

		float getArea() {
			float radius = this->getRadius();
			return 4 * radius * radius;
		}

		float getPerim() {
			float radius = this->getRadius();
			return 8 * radius;
		}
};

void print(Shape* p);

void print(Shape* p)
{
	cout<<"shape's area and perim:"<<endl;
	cout<<"area: "<<p->getArea()<<" ";
	cout<<"perim: "<<p->getPerim()<<endl;
}

int main()
{
	Shape* pc = new Circle(4);
	print(pc);
	Shape* pi = new InnerSquare(4);
	print(pi);
	Shape* po = new OuterSquare(4);
	print(po);

	delete pc;
	pc = NULL;
	delete pi;
	pi = NULL;
	delete po;
	po = NULL;

	return 0;
}
