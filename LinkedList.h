#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>

template <class T>
struct Node {
	T     data;
	Node *next;
};

template <class T>
class LinkedList {
public:
	LinkedList() :
		first(nullptr),
		current_size(0) {}

	~LinkedList() {
		auto* iter = first;

		while (iter) 
			delete std::exchange(iter, iter->next);
	}

	inline size_t size() const { 
		return current_size;
	}

	void insert(const T& element) {
		first = new Node<T>{ element, first };
		current_size++;
	}

	virtual bool erase(T& erased) {                             // erases last element
		if (!first) return false;
		if (!first->next) {
			erased = first->data;
			delete std::exchange(first, nullptr);
			current_size = 0;
			return true;
		}

		auto* iter = first;
		while (iter->next->next)
			iter = iter->next; 
		
		erased = iter->next->data;
		delete std::exchange(iter->next, nullptr);
		current_size--;

		return true;
	}

	void print() {
		if (!first) return;

		auto  count = 1u;
		auto* iter  = first;

		std::cout << "[" << count++ << "|" << iter->data;
		while (iter = iter->next)
			std::cout << "]->" << "[" << count++ << "|" << iter->data;
		std::cout << "]\n";
	}

protected:
	Node<T>* first;
	size_t   current_size;
};

#endif /* __LINKEDLIST__ */