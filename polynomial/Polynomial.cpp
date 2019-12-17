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
#include "polynomial_item.h"
using namespace std;

#define NL "\n"

class Polynomial {
		/* Actually, we should store all items
		 * in a linkedlist.
		 * Storage structure is simplified here.
		 */
	private:
		Item *items;
		int n;

	public:
		Polynomial(int n);

		~Polynomial() {
			delete []items;
			items = NULL;
			cout<<"destructor called"<<NL;
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

		Polynomial operator+=(const Polynomial& other);

		// second implementation, friend function
		friend Polynomial operator-(Polynomial& a,Polynomial& b);

		friend Polynomial operator-=(Polynomial& a,Polynomial& b);
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

Polynomial Polynomial::operator+=(const Polynomial& other)
{
	static Polynomial ret = this->operator+(other);
	// free before
	this->~Polynomial();
	// assignment
	this->items = ret.items;
	this->n = ret.n;
	return *this;
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

Polynomial operator-=(Polynomial& a,Polynomial& b)
{
	static Polynomial ret = a - b;
	// free before
	a.~Polynomial();
	// assignment
	a.items = ret.items;
	a.n = ret.n;
	return a;
}

void Polynomial::print()
{
	for(int i=0; i<n-1; i++) {
		items[i].print();
		cout<<" + ";
	}
	items[n-1].print();
	cout<<NL;
}

// test
int main()
{
	// test Item
	/*
	Item item(2,4);
	item.print();
	cout<<NL;
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
	cout<<"p(x) + q(x) = ";
	pPlusq.print();

	Polynomial pSubq = *p - *q;
	cout<<"p(x) - q(x) = ";
	pSubq.print();

	*p += *q;
	cout<<"after p(x)+=q(x), p(x) = ";
	p->print();

	*p -= *q;
	cout<<"after p(x)-=q(x), p(x) = ";
	p->print();

	delete p;
	p = NULL;
	delete q;
	q = NULL;

	return 0;
}
