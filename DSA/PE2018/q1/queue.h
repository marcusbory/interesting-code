#pragma once

#include "linkedlist.h"

template <class T>
class Queue {
private:
	LinkedList<T> *_queue;

public:
	Queue() {
		_queue = new LinkedList<T>();
	}

	// Task 5: Implement enqueue, peek and dequeue operations on a Queue.
	void enqueue(T);
	T peek();
	T dequeue();

	void print();
};

#include "queue.hpp"