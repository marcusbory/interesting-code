#include <iostream>
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
using namespace std;

#define INVALID -1
#define NUM_1 10
#define NUM_2 20
#define NUM_3 30

void testIntLinkedListInsertHead(); // Task 1
void testIntLinkedListDeleteHead(); // Task 2
void testIntStackOperations();		// Task 3
void testIntLinkedListInsertTail(); // Task 4
void testIntQueueOperations();		// Task 5
void testIntLinkedListDeleteTail(); // Task 6

int main()
{
	// After completing Task 1, uncomment this
	testIntLinkedListInsertHead();

	// After completing Task 1 & 2, uncomment this
	testIntLinkedListDeleteHead();

	// After completing Task 1 & 2 & 3, uncomment this
	testIntStackOperations();

	// After completing Task 4, uncomment this
	testIntLinkedListInsertTail();

	// After completing Task 2 & 4 & 5, uncomment this
	testIntQueueOperations();

	// After completing Task 1 & 6, uncomment this
	testIntLinkedListDeleteTail();

	return 0;
}

void testIntLinkedListInsertHead() {
	LinkedList <int> ll;

	cout << "Task 1: Testing LinkedList<int> insertHead()." << endl;
	cout << "=============================================" << endl;

	// Linked List, 0 elements

	cout << "print() Expected Value: " << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << INVALID << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << INVALID << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 1 element
	cout << "Inserting value " << NUM_1 << " to head of linked list." << endl;
	ll.insertHead(NUM_1);

	cout << "print() Expected Value: " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_1 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_1 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 2 elements
	cout << "Inserting value " << NUM_2 << " to head of linked list." << endl;
	ll.insertHead(NUM_2);

	cout << "print() Expected Value: " << NUM_2 << " " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_2 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_1 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 3 elements
	cout << "Inserting value " << NUM_3 << " to head of linked list." << endl;
	ll.insertHead(NUM_3);

	cout << "print() Expected Value: " << NUM_3 << " " << NUM_2 << " " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_3 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_1 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl << endl;
}

void testIntLinkedListDeleteHead() {
	LinkedList <int> ll;

	ll.insertHead(NUM_1);
	ll.insertHead(NUM_2);
	ll.insertHead(NUM_3);

	cout << "Task 2: Testing LinkedList<int> deleteHead()." << endl;
	cout << "=============================================" << endl;

	// Linked List, 2 elements
	cout << "Deleting head from linked list." << endl;
	ll.deleteHead();

	cout << "print() Expected Value: " << NUM_2 << " " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_2 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_1 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 1 element
	cout << "Deleting head from linked list." << endl;
	ll.deleteHead();

	cout << "print() Expected Value: " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_1 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_1 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 0 elements
	cout << "Deleting head from linked list." << endl;
	ll.deleteHead();

	cout << "print() Expected Value: " << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << INVALID << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << INVALID << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	//Linked List, attempt to delete from empty
	cout << "Deleting head from empty linked list." << endl;
	ll.deleteHead();
	cout << endl;

	// Linked List, re-insert
	cout << "Inserting value " << NUM_1 << " to head of linked list." << endl;
	ll.insertHead(NUM_1);

	cout << "print() Expected Value: " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << endl << endl;

}

void testIntStackOperations() {
	Stack <int> s;

	cout << "Task 3: Testing Stack<int> operations." << endl;
	cout << "======================================" << endl;

	// Stack, 0 elements
	cout << "print() Expected Value: " << endl;
	cout << "print() Actual Value:   ";
	s.print();

	cout << "peek() Expected Value: " << INVALID << endl;
	cout << "peek() Actual Value:   " << s.peek() << endl;

	cout << "pop() Expected Value: " << INVALID << endl;
	cout << "pop() Actual Value:   " << s.pop() << endl;

	cout << endl;

	// Stack, 1 element
	cout << "Pushing value " << NUM_1 << " to top of stack." << endl;
	s.push(NUM_1);

	cout << "peek() Expected Value: " << NUM_1 << endl;
	cout << "peek() Actual Value:   " << s.peek() << endl;

	cout << endl;

	// Stack, 2 elements
	cout << "Pushing value " << NUM_2 << " to top of stack." << endl;
	s.push(NUM_2);

	cout << "peek() Expected Value: " << NUM_2 << endl;
	cout << "peek() Actual Value:   " << s.peek() << endl;

	cout << "print() Expected Value: " << NUM_2 << " " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	s.print();

	cout << endl;

	// Stack, removal of elements
	cout << "Popping from top of stack." << endl;
	cout << "pop() Expected Value: " << NUM_2 << endl;
	cout << "pop() Actual Value:   " << s.pop() << endl;

	cout << "Popping from top of stack again." << endl;
	cout << "pop() Expected Value: " << NUM_1 << endl;
	cout << "pop() Actual Value:   " << s.pop() << endl;

	cout << "print() Expected Value: " << endl;
	cout << "print() Actual Value:   ";
	s.print();

	cout << endl << endl;
}

void testIntLinkedListInsertTail() {
	LinkedList <int> ll;

	cout << "Task 4: Testing LinkedList<int> insertTail()." << endl;
	cout << "=============================================" << endl;

	// Linked List, 1 element
	cout << "Inserting value " << NUM_1 << " to tail of linked list." << endl;
	ll.insertTail(NUM_1);

	cout << "print() Expected Value: " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_1 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_1 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 2 elements
	cout << "Inserting value " << NUM_2 << " to tail of linked list." << endl;
	ll.insertTail(NUM_2);

	cout << "print() Expected Value: " << NUM_1 << " " << NUM_2 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_1 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_2 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 3 elements
	cout << "Inserting value " << NUM_3 << " to head of linked list." << endl;
	ll.insertTail(NUM_3);

	cout << "print() Expected Value: " << NUM_1 << " " << NUM_2 << " " << NUM_3 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_1 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_3 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl << endl;
}

void testIntQueueOperations() {
	Queue <int> q;

	cout << "Task 5: Testing Queue<int> operations." << endl;
	cout << "======================================" << endl;

	// Queue, 0 elements
	cout << "print() Expected Value: " << endl;
	cout << "print() Actual Value:   ";
	q.print();

	cout << "peek() Expected Value: " << INVALID << endl;
	cout << "peek() Actual Value:   " << q.peek() << endl;

	cout << "dequeue() Expected Value: " << INVALID << endl;
	cout << "dequeue() Actual Value:   " << q.dequeue() << endl;

	cout << endl;

	// Queue, 1 element
	cout << "Offering value " << NUM_1 << " to end of queue." << endl;
	q.enqueue(NUM_1);

	cout << "peek() Expected Value: " << NUM_1 << endl;
	cout << "peek() Actual Value:   " << q.peek() << endl;

	cout << endl;

	// Queue, 2 elements
	cout << "Offering value " << NUM_2 << " to end of queue." << endl;
	q.enqueue(NUM_2);

	cout << "peek() Expected Value: " << NUM_1 << endl;
	cout << "peek() Actual Value:   " << q.peek() << endl;

	cout << "print() Expected Value: " << NUM_1 << " " << NUM_2 << endl;
	cout << "print() Actual Value:   ";
	q.print();

	cout << endl;

	// Queue, removal of elements
	cout << "Polling from start of queue." << endl;
	cout << "dequeue() Expected Value: " << NUM_1 << endl;
	cout << "dequeue() Actual Value:   " << q.dequeue() << endl;

	cout << "Polling from top of stack again." << endl;
	cout << "dequeue() Expected Value: " << NUM_2 << endl;
	cout << "dequeue() Actual Value:   " << q.dequeue() << endl;

	cout << "print() Expected Value: " << endl;
	cout << "print() Actual Value:   ";
	q.print();

	cout << endl << endl;
}

void testIntLinkedListDeleteTail() {
	LinkedList <int> ll;

	ll.insertHead(NUM_1);
	ll.insertHead(NUM_2);
	ll.insertHead(NUM_3);

	cout << "Task 6: Testing LinkedList<int> deleteTail()." << endl;
	cout << "=============================================" << endl;

	// Linked List, 2 elements
	cout << "Deleting tail from linked list." << endl;
	ll.deleteTail();

	cout << "print() Expected Value: " << NUM_3 << " " << NUM_2 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_3 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_2 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 1 element
	cout << "Deleting tail from linked list." << endl;
	ll.deleteTail();

	cout << "print() Expected Value: " << NUM_3 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << NUM_3 << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << NUM_3 << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	// Linked List, 0 elements
	cout << "Deleting tail from linked list." << endl;
	ll.deleteTail();

	cout << "print() Expected Value: " << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << "getHead() Expected Value: " << INVALID << endl;
	cout << "getHead() Actual Value:   " << ll.getHead() << endl;

	cout << "getTail() Expected Value: " << INVALID << endl;
	cout << "getTail() Actual Value:   " << ll.getTail() << endl;

	cout << endl;

	//Linked List, attempt to delete from empty
	cout << "Deleting tail from empty linked list." << endl;
	ll.deleteTail();
	cout << endl;

	// Linked List, re-insert
	cout << "Inserting value " << NUM_1 << " to head of linked list." << endl;
	ll.insertHead(NUM_1);

	cout << "print() Expected Value: " << NUM_1 << endl;
	cout << "print() Actual Value:   ";
	ll.print();

	cout << endl << endl;

}