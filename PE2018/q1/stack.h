#pragma once

#include "linkedlist.h"

template <class T>
class Stack {
private:
	LinkedList<T> *_stack;

public:
	Stack() {
		_stack = new LinkedList<T>();
	}

	// Task 3: Implement push, peek and pop operations of a stack using a single linked list.
	void push(T);
	T peek();
	T pop();

	void print();
};

#include "stack.hpp"