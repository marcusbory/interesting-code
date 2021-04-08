#pragma once

#ifndef LINKEDLISTHPP
#define LINKEDLISTHPP

#include <iostream>
#include "linkedlist.h"
using namespace std;


template <class T>
LinkedListNode<T>::LinkedListNode(T item) {
	_item = item;
	_next = NULL;
}

// Task 1: Augment the function to cater for tail node. Hint: 2 lines of code added.
template <class T>
void LinkedList<T>::insertHead(T item) {
	LinkedListNode<T>* newNode = new LinkedListNode<T>(item);
	newNode->_next = _head;
	_head = newNode;
	if (_size == 0)
		_tail = _head;
	
	_size++;
}

template <class T>
T LinkedList<T>::getHead() {
	if (_size)
		return _head->getItem();
	else return -1;
}

// Task 2: Augment the function to cater for tail node. Hint: 2 lines of code added.
template <class T>
void LinkedList<T>::deleteHead() {
	if (_size > 0) {
		LinkedListNode<T> *temp = _head;
		_head = _head->_next;
		if (_size == 1)
			_tail = nullptr;
		
		delete temp;

		_size--;
	}
}

// Task 4: Implement the function to add a node after the tail.
template <class T>
void LinkedList<T>::insertTail(T item) {
	if (_size == 0) 
		insertHead(item);
	else {
		LinkedListNode<T>* temp = new LinkedListNode<T>(item);
		_tail->_next = temp;
		_tail = temp;
		_size++;
	}
}

template <class T>
T LinkedList<T>::getTail() {
	if (_size)
		return _tail->getItem();
	else return -1;
}

// Task 6: Implement the function to delete a tail node.
template <class T>
void LinkedList<T>::deleteTail() {
	if (_size == 0) 
		return;
	LinkedListNode<T>* temp = _head;
	LinkedListNode<T>* temp2 = nullptr;
	while (temp->_next) {
		temp2 = temp;
		temp = temp->_next;
	}
	if (_tail == _head) {
		_head = _tail = nullptr;
	}
	else {
		_tail = temp2;
		_tail->_next = nullptr;
	}
	delete temp;
	_size--;
}

template <class T>
void LinkedList<T>::print() {

	LinkedListNode<T> *temp = _head;
	while (temp) {
		cout << temp->_item;
		cout << " ";
		temp = temp->_next;
	}
	cout << endl;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (_head)
		deleteHead();
}

#endif