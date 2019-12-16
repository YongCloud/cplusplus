/*
 * Polynomial class
 * This file demonstates how to
 * to implement operator overlaod
 * in C++
 *
 * author xingjian
 * since 2019/12/16
 */
#include <iostream>
#include <stdexcept>
using namespace std;

class Item {
	private:
		// coefficient
		float coef;
		// exponent
		int exp;
	public:
		Item() {
			this->coef = 0;
			this->exp = 0;
		}

		Item(float coef,int exp) {
			this->coef = coef;
			this->exp = exp;
		}

		float getCoef() {
			return this->coef;
		}

		int getExp() {
			return this->exp;
		}

		void setCoef(float coef) {
			this->coef = coef;
		}

		void setExp(int exp) {
			this->exp = exp;
		}

		void print();
};

void Item::print()
{
	cout<<coef;
	if(exp==0) {
		// print nothing
	} else if(exp==1) {
		cout<<"x";
	} else {
		cout<<"x^"<<exp;
	}
}

class Polynomial {
	private:
		Item *items;
		int n;

	public:
		Polynomial(int n);

		~Polynomial() {
			delete []items;
			cout<<"destructor called"<<endl;
		}

		int getN() {
			return n;
		}

		Item* getItem(int index);

		Item* getItemWithExp(int exp) const;

		void set(int index,float coef,int exp);

		void set(int index,float coef);

		void set(int index,int exp);

		void print();

		// first implementation, member function
		Polynomial operator+(const Polynomial& other);

		// second implementation, friend function
		friend Polynomial operator-(Polynomial& a,Polynomial& b);
};

Polynomial::Polynomial(int n)
{
	if(n<=0) {
		throw invalid_argument("invalid argument, n <= 0");
	}
	items = new Item[n];
	if(items == NULL) {
		throw runtime_error("Failed to apply for memory");
	}
	this->n = n;
}

Item* Polynomial::getItem(int index)
{
	if(index<0 || index>=n) {
		return NULL;
	}
	return (items+index);
}

Item* Polynomial::getItemWithExp(int exp) const
{
	for(Item* pi=items; pi<=items+n-1; pi++) {
		if(pi->getExp() == exp) {
			return pi;
		}
	}
	return NULL;
}

void Polynomial::set(int index,float coef,int exp)
{
	if(index<0 || index>=n) {
		return;
	}
	Item* item = items+index;
	item->setCoef(coef);
	item->setExp(exp);
}

void Polynomial::set(int index,float coef)
{
	if(index<0 || index>=n) {
		return;
	}
	Item* item = items+index;
	item->setCoef(coef);
}

void Polynomial::set(int index,int exp)
{
	if(index<0 || index>=n) {
		return;
	}
	Item* item = items+index;
	item->setExp(exp);
}

Polynomial Polynomial::operator+(const Polynomial& other)
{
	int length = n>other.n?n:other.n;
	Polynomial ret(length);
	for(int i=0; i<length; i++) {
		// exponent, from high to low
		int e = length - i - 1;
		Item* a = getItemWithExp(e);

		Item* b = other.getItemWithExp(e);
		if(a!=NULL && b!=NULL) {
			ret.set(i,a->getCoef()+b->getCoef(),e);
		} else if(a != NULL) {
			ret.set(i,a->getCoef(),e);
		} else if(b != NULL) {
			ret.set(i,b->getCoef(),e);
		}
	}
	return ret;
}

Polynomial operator-(Polynomial& a,Polynomial& b)
{
	int length = a.getN()>b.getN()?a.getN():b.getN();
	Polynomial ret(length);
	for(int i=0; i<length; i++) {
		// exponent, from high to low
		int e = length - i - 1;
		Item* pa = a.getItemWithExp(e);
		Item* pb = b.getItemWithExp(e);
		if(pa!=NULL && pb!=NULL) {
			ret.set(i,pa->getCoef() - pb->getCoef(),e);
		} else if(pa != NULL) {
			ret.set(i,pa->getCoef(),e);
		} else if(pb != NULL) {
			ret.set(i,pb->getCoef(),e);
		}
	}
	return ret;
}


void Polynomial::print()
{
	for(int i=0; i<n-1; i++) {
		items[i].print();
		cout<<" + ";
	}
	items[n-1].print();
	cout<<endl;
}

// test
int main()
{
	// test Item
	/*
	Item item(2,4);
	item.print();
	cout<<endl;
	*/

	/*
	 * Polynomial test
	 * p(x) = 4x^3 + 3x^2 + 2x + 1
	 * q(x) = 7x^2 + 5
	 */
	Polynomial* p = new Polynomial(4);
	p->set(0,4,3);
	p->set(1,3,2);
	p->set(2,2,1);
	p->set(3,1,0);
	cout<<"p(x) = ";
	p->print();

	Polynomial* q = new Polynomial(2);
	q->set(0,7,2);
	q->set(1,5,0);
	cout<<"q(x) = ";
	q->print();

	Polynomial pPlusq = *p + *q;
	Polynomial pSubq = *p - *q;
	cout<<"p(x) + q(x) = ";
	pPlusq.print();
	cout<<"p(x) - q(x) = ";
	pSubq.print();

	delete p;
	p = NULL;
	delete q;
	q = NULL;

	return 0;
}
