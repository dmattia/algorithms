// a simple stack based on a linked list

#ifndef STACK_H
#define STACK_H

#include "../linked_list/List.h"

template <class T>
class Stack {
public:
	Stack() {
		_size = 0;
	}
	//O(1)
	void push(T item) {
		// add item to back of stack
		list.push_front(item);
		_size++;
	}
	//O(1)
	T top() {
		// return the last item pushed onto the stack
		if(list.front() != NULL) {
			return list.front()->value;
		} else {
			throw std::out_of_range("No items left on stack");
		}
	}
	//O(1)
	T pop() {
		// remove next value and return it
		_size--;
		return list.pop_front();
	}
	//O(1)
	int empty() {
		// returns if the list is empty
		return list.empty();
	}
	//O(1)
	int size() {
		// returns the amount of items on the stack
		return _size;
	}
private:
	List<T> list;
	int _size;
};

#endif
