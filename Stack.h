#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T>
{
	using Mybase = LinkedList<T>;

public:
	using Mybase::Mybase;
	virtual ~Stack() = default;

	bool erase (T& erased) override {
		if (!Mybase::first) return false;

		erased = Mybase::first->data;
		delete std::exchange(Mybase::first, Mybase::first->next);
		Mybase::current_size--;

		return true;
	}
};
