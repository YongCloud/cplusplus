/*
 * Supplying basic implementation of List, to minimize implementation of List.
 *
 * author xinjian
 * since 2019/12/12
 */
#include "List.h"

template <typename T>
class AbstractList : public List<T>
{
	public:
		bool isEmpty() {
			return this->size() == 0;
		}
};

