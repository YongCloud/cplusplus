/*
 * encapsulation of an item in a polynomial.
 *
 * author xingjian
 * since 2019/12/16
 */
#ifndef POLYNOMIAL_ITEM_H
#define POLYNOMIAL_ITEM_H
#include <iostream>
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
#endif
