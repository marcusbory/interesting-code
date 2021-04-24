#pragma once

#ifndef QUEUEHPP
#define QUEUEHPP

#include <iostream>
#include "queue.h"
using namespace std;

// Task 5: Implement enqueue, peek and dequeue operations on a Queue.

template <class T>
void Queue<T>::enqueue(T _item) {
	_queue->insertTail(_item);
}

template <class T>
T Queue<T>::peek() {
	T item = _queue->getHead();
	return item;
}

template <class T>
T Queue<T>::dequeue() {
	T item = _queue->getHead();
	_queue->deleteHead();
	return item;
}


template <class T>
void Queue<T>::print() {
	_queue->print();
}
#endif