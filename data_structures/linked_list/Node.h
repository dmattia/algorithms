// A node for a linked list

#ifndef NODE_H
#define NODE_H

#include <cstddef>

template <class T>
class Node {
public:
	Node(void) : next(NULL) {}
	Node(T value) : value(value), next(NULL) {}
	Node(T value,Node<T>* next) : value(value), next(next) {}
	T getValue() {return value;}
	Node<T>* getNext() {return next;}

	// Public data members
	T value;
	Node<T>* next;
};

#endif
