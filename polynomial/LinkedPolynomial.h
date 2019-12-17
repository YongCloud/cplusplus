/*
 * Linked storage structure of
 * polynomial and its operations.
 *
 * author xingjian
 * since 2019/12/16
 */
#ifndef LINKED_POLYNOMIAL_H
#define LINKED_POLYNOMIAL_H
#include "polynomial_item.h"

class LinkedPolynomial {
	private:
		// store all items in a linkedlist.
		Item* head;
	public:
		LinkedPolynomial();

		~LinkedPolynomial();

		Item* getItem(int index);

		Item* getItemWithExp(int exp) const;

		void set(int index,float coef,int exp);

		void set(int index,float coef);

		void set(int index,int exp);

		bool add(float coef,int exp);

		float eval(float x);

		void print();

		// first implementation, member function
		LinkedPolynomial operator+(const LinkedPolynomial& other);

		// second implementation, friend function
		friend LinkedPolynomial operator-(LinkedPolynomial& a,LinkedPolynomial& b);

		LinkedPolynomial operator*(const LinkedPolynomial& other);

		LinkedPolynomial operator/(const LinkedPolynomial& other);
};
#endif
