/*
 * polymorphism demonstration with C++.
 * implement polymorphism with virtual class.
 *
 * author xingjian
 * since 2019/12/17
 */
#include <iostream>
using namespace std;

#define PI 3.1415926535

class Shape {
	public:
		virtual float Area() = 0;
};

class Rectangle:public Shape {
	private:
		float length;
		float width;
	public:
		Rectangle() {
			this->length = 0;
			this->width = 0;
		}

		Rectangle(float length,float width) {
			this->length = length;
			this->width = width;
		}

		float Area() {
			return length * width;
		}

		float getLength() {
			return this->length;
		}

		float getWidth() {
			return this->width;
		}

		void setLength(float length) {
			this->length = length;
		}

		void setWidth(float width) {
			this->width = width;
		}
};

class Circle:public Shape {
	private:
		float r;
	public:
		Circle() {
			this->r = 0;
		}

		Circle(float r) {
			this->r = r;
		}

		float Area() {
			return PI * r * r;
		}

		float getR() {
			return this->r;
		}

		void setR(float r) {
			this->r = r;
		}
};

class Square:public Rectangle {
	public:
		Square():Rectangle(0,0) {
		}

		Square(float edge):Rectangle(edge,edge) {
		}
};

int main()
{
	Shape* rect = new Rectangle(3,5);
	cout<<"rectangle's area: "<<rect->Area()<<endl;

	Shape* circle = new Circle(4);
	cout<<"circle's area: "<<circle->Area()<<endl;

	Shape* square = new Square(3);
	cout<<"square's area: "<<square->Area()<<endl;

	delete rect;
	rect = NULL;
	delete circle;
	circle = NULL;
	delete square;
	square = NULL;

	return 0;
}
