/*
 Complex encapsulation
 author xingjian
 since 2019/12/09
*/
#include <iostream>
using namespace std;

class Complex {
	private:
		float real;
		float img;
	public:
		Complex(float r = 0, float i = 0) {
			real = r;
			img = i;
		}

		float getReal() {
			return real;
		}

		float getImg() {
			return img;
		}

		void setReal(float r) {
			real = r;
		}

		void setImg(float i) {
			img = i;
		}

		Complex add(Complex c);

		Complex subtract(Complex c);

		void print() {
			cout<<"("<<real<<","<<img<<")"<<endl;
		}
};

Complex Complex::add(Complex c)
{
	float r = real + c.getReal();
	float i = img + c.getImg();
	Complex ret(r,i);
	return ret;
}

Complex Complex::subtract(Complex c)
{
	float r = real - c.getReal();
	float i = img - c.getImg();
	Complex ret(r,i);
	return ret;
}

int main()
{
	Complex a(1,3);
	Complex b(5,7);
	Complex c = a.add(b);
	Complex d = a.subtract(b);

	a.print();
	b.print();
	c.print();
	d.print();

	return 0;
}
