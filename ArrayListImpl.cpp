/*
 * List implementation, element stored in dynamic array.
 *
 * author xinjian
 * since 2019/12/12
 */
#include "AbstractList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class ArrayListImpl : public AbstractList<T> {
	private:
		T *elements;
		int num;
		int length;

		bool resize();

		void checkInsertRange(int index);

		void checkRange(int index);

		bool addElement(T e) {
			elements[num] = e;
			num++;
			return true;
		}

		bool insertElement(T e, int index);
	public:
		ArrayListImpl() {
			cout<<"constructor with no parameter"<<endl;
			this->elements = NULL;
			this->num = 0;
			this->length = 0;
		}

		ArrayListImpl(int capacity);

		bool add(T e);

		bool insert(T e, int index);

		T get(int index);

		T remove(int index);

		int size() {
			return num;
		}

		void print();
};

template <typename T>
ArrayListImpl<T>::ArrayListImpl(int capacity)
{
	if(capacity < 0) {
		throw invalid_argument("invalid argument, capacity < 0");
	}
	if(capacity == 0) {
		this->ArrayListImpl();
	} else {
		elements = new T[capacity];
		if(elements == NULL) {
			cout<<"Failed to apply for memory."<<endl;
		} else {
			length = capacity;
			num = 0;
		}
	}
}

template <typename T>
bool ArrayListImpl<T>::add(T e)
{
	if(num >= length) {
		bool res = resize();
		if(!res) {
			return res;
		}
		return addElement(e);
	} else {
		return addElement(e);
	}
}

template <typename T>
bool ArrayListImpl<T>::insert(T e, int index)
{
	checkInsertRange(index);
	int n = num + 1;
	if(n >= length) {
		bool res = resize();
		if(!res) {
			return res;
		}
		return insertElement(e,index);
	} else {
		return insertElement(e,index);
	}
}

template <typename T>
T ArrayListImpl<T>::get(int index)
{
	checkRange(index);
	return *(elements+index);
}

template <typename T>
T ArrayListImpl<T>::remove(int index)
{
	checkRange(index);
	T ret = *(elements+index);
	for(int i = index; i<num-1; i++) {
		*(elements+i) = *(elements+i+1);
	}
	return ret;
}

template <typename T>
void ArrayListImpl<T>::print()
{
	cout<<"[";
	int i = 0;
	for(i = 0; i < num-1; i++) {
		cout<<*(elements+i)<<",";
	}
	cout<<*(elements+i)<<"]";
}

template <typename T>
bool ArrayListImpl<T>::resize()
{
	T *pre = elements;
	// expansion
	elements = new T[2*length];
	if(elements == NULL) {
		cout<<"Failed to apply for memory."<<endl;
		elements = pre;
		return false;
	}
	length = 2*length;
	// copy elements
	for(int i = 0; i < num; i++) {
		*(elements+i) = *(pre+i);
	}
	// free memory
	delete []pre;
	pre = NULL;
	return true;
}

template <typename T>
void ArrayListImpl<T>::checkInsertRange(int index)
{
	if(index < 0 || index > num) {
		throw out_of_range("insert index out of range");
	}
}

template <typename T>
void ArrayListImpl<T>::checkRange(int index)
{
	if(index < 0 || index >= num) {
		throw out_of_range("index out of range");
	}
}

template <typename T>
bool ArrayListImpl<T>::insertElement(T e, int index)
{
	for(int i = 0; i < num - index; i++) {
		*(elements+num+i) = *(elements+index+i);
	}
	*(elements+index) = e;
	num++;
	return true;
}

// test
int main()
{
	/*
	  Once add following two lines,
	  there are compilation errors,
	  so what happened?
	*/
	List<int> *p = new ArrayListImpl<int>();
	p->print();

	return 0;
}
