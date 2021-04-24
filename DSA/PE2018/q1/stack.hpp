#pragma once

#ifndef STACKHPP
#define STACKHPP

#include <iostream>
#include "stack.h"
using namespace std;

// Task 3: Implement push, peek and pop operations of a stack using a single linked list.

template <class T>
void Stack<T>::push(T _item) {
	_stack->insertHead(_item);
}

template <class T>
T Stack<T>::peek() {
	T item = _stack->getHead();
	return item;
}

template <class T>
T Stack<T>::pop() {
	T item = _stack->getHead();
	_stack->deleteHead();
	return item;
}

template <class T>
void Stack<T>::print() {
	_stack->print();
}

#endif