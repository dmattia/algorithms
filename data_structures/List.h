// Header file for my linked list implementation

#ifndef LIST_H
#define LISH_H

#include "Node.h"
#include <iostream>
#include <cstddef>

template <typename T>
class List {
public:
	List() {
		head = NULL;
	}
	void printList() {
		std::cout << "printing list: ";
		Node<T>* p = head;
		while(p != NULL) {
			std::cout << p->getValue() << " ";
			p = p->getNext();
		}
		std::cout << std::endl;
	}
	void push_front(T value) {
		// add a node to the front of the list
		Node<T>* next = head;
		head = new Node<T>(value,next);
	}
	int size() {
		int size = 0;
		Node<T>* p = head;
		while(p != NULL) {
			size++;
			p = p->getNext();
		}
		return size;
	}
private:
	Node<T>* head;	
};

#endif
