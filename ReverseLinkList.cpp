#include <iostream>
using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node {
private:
  T _item;
  Node<T>* _next;
public:
  Node(T x) {
    _item = x;
    _next = nullptr;
  }
  T content() { return _item; }
  void print() { cout << _item; }
  friend class LinkedList<T>;
};

template <class T>
class LinkedList {
private:
  Node<T>* _head;
  int _size;
public:
  LinkedList() {
    _head = nullptr;
    _size = 0;
  }
  void insertHead(T);
  void print();
  int size() { return _size; }
  // Main function
  void reverse();
};

template <class T>
void LinkedList<T>::insertHead(T x) {
  Node<T>* t = new Node<T>(x);
  t->_next = _head;
  _head = t;
  _size++;
}

template <class T>
void LinkedList<T>::print() {
  Node<T>* t = _head;
  while (t) { 
    cout << t->_item << " ";
    t = t->_next;
  }
  cout << endl;
}

template <class T>
void LinkedList<T>::reverse() {
  Node<T>* first, * second, * third;
  first = _head; second = third = nullptr;
  while (first != nullptr) {
    third = second;
    second = first;
    first = first->_next;
    second->_next = third;
  }
  _head = second;
}

int main() {
  LinkedList<int> l;
  for (int i = 10; i > 0; i--) 
    l.insertHead(i);
  l.print();
  l.reverse();
  l.print();
  return 0;
}
