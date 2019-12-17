/*
 * A abstract interface of List data structure.
 *
 * author xinjian
 * since 2019/12/12
 */
#ifndef LIST_H
#define LIST_H 
template <typename T>
class List
{
	public:
		// add operations
		/*
		 * add element to the tail of list.
		 *
		 * param e
		 * return true if OK, false otherwise
		 */
		virtual bool add(T e);

		/*
		 * insert element at given position.
		 *
		 * param e
		 * param index
		 * return true if OK, false otherwise
		 */
		virtual bool insert(T e, int index);

		// get operation
		/*
		 * get element by index.
		 *
		 * param index
		 * return element indicated by index
		 */
		virtual T get(int index);

		// remove operation
		/*
		 * remove element at given position.
		 *
		 * param index
		 * return element removed
		 */
		virtual T remove(int index);

		// other operations
		/*
		 * get size of list.
		 *
		 * return number of element in the list
		 */
		virtual int size();

		/*
		 * test if this list is empty.
		 *
		 * return true if empty, false otherwise
		 */
		virtual bool isEmpty();

		/*
		 * print all elements int the List.
		 */
		virtual void print();
};
#endif
