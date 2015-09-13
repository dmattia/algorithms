// Header file for my linked list implementation

#ifndef LIST_H
#define LISH_H

#include "Node.h"
#include <iostream>
#include <cstddef>
#include <stdexcept>

template <class T>
class List {
public:
	List() {
		head = NULL;
	}
	~List() {
		clear();
	}
	//O(n)
	void clear() {
		Node<T>* current = front();
		while(current != NULL) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
		head = NULL;
	}
	//O(n)
	void printList() {
		std::cout << "printing list: ";
		Node<T>* p = head;
		while(p != NULL) {
			std::cout << p->getValue() << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}
	//O(1)
	Node<T>* front() {
		return head;
	}
	//O(n)
	Node<T>* back() {
		if (empty()) return NULL;

		Node<T>* p = front();
		Node<T>* next = p->next;
		while(next != NULL) {
			p = next;
			next = next->next;
		}
		return p;
	}
	//O(1)
	void push_front(T value) {
		// add a node to the front of the list
		Node<T>* next = front();
		head = new Node<T>(value,next);
	}
	//O(n)
	void push_back(T value) {
		// add a node to the end of the list
		Node<T>* end = back();
		end->next = new Node<T>(value);
	}
	//O(n)
	void insert(T value, int index) {
		if(index == 0) {
			push_front(value);
			return;
		}
		//inserts a new node before location index
		if(size() < index || index < 0) {
			throw std::invalid_argument("cannot insert at that index."); 
		}
		Node<T>* p = front();
		Node<T>* next = p;
		for(int i=1; i < index; ++i) {
			p = p->next;
		}
		next = p->next;
		p->next = new Node<T>(value,next);
	}
	//O(n)
	int size() {
		int size = 0;
		Node<T>* p = front();
		while(p != NULL) {
			size++;
			p = p->next;
		}
		return size;
	}
	//O(1)
	int empty() {
		return front() == NULL;
	}
private:
	Node<T>* head;	
};

#endif
