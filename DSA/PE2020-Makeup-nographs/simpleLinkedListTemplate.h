#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
template <class T>
class List;


template <class T>
class ListNode
{
private:
	T _item;
	ListNode<T> *_next;

public:
	ListNode(T);
	T content() { return _item; };
	friend class List<T>;
};

template <class T>
class List
{
private:
	int _size;
	ListNode<T> *_head;
	ListNode<T>* _current;

public:

	// for the following functions, you cannot assume that the list is not empty or empty...
	List() { _size = 0;	_head = NULL; _current = NULL;  };

	~List();
	void insert(T); // Assume inserting at the head

	void print(bool withoutSpace = false); // print the items in one single row if false, otherwise, print each item in a new line
	int size() { return _size; };
	bool exist(T);
	bool empty() { return _size == 0; };


	// .. except for the following functionse can assume that the list is not empty when you call them.
	T headItem();
	void removeHead();
	void removePos(int idx);

	T operator[](int idx);
	void swap(int idx1, int idx2); // swap the contents of items at indices idx1 and idx2

	// Simple Iterator
	void start() { _current = _head; };
    T current() { assert(_current); return _current->_item; };
	void next() { if (_current) _current = _current->_next; };
	bool end() { return _current == NULL;};
		
};

template <class T>
class SortedList : public List<T> {

public:
	void insert(T x) { List<T>::insert(x); sort(); }
	void sort();

};

#include "simpleLinkedListTemplate.cpp"
