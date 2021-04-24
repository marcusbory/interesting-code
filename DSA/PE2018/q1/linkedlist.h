#pragma once
using namespace std;
template <class T>
class LinkedList;

template <class T>
class LinkedListNode {
private:
	T _item;
	LinkedListNode<T> *_next;

public:
	LinkedListNode(T);
	T getItem() { return _item; };
	void printItem() { cout << _item; };
	friend class LinkedList<T>;
};

template <class T>
class LinkedList {
private:
	int _size;
	LinkedListNode<T> *_head;
	LinkedListNode<T> *_tail;

public:
	LinkedList() {
		_size = 0;
		_head = NULL;
		_tail = NULL;
	};

	~LinkedList();

	void insertHead(T); // Task 1: Augment the function to cater for tail node. Hint: 2 lines of code added.
	T getHead();
	void deleteHead();	// Task 2: Augment the function to cater for tail node. Hint: 2 lines of code added.

	void insertTail(T);	// Task 4: Implement the function to add a node after the tail.
	T getTail();
	void deleteTail();	// Task 6: Implement the function to delete a tail node.

	void print();

	int getSize() {
		return _size;
	}

	bool isEmpty() {
		return _size == 0;
	}
};

#include "linkedlist.hpp"
