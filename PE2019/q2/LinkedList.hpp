#pragma once

#ifndef LINKEDLIST_HPP_
#define LINKEDlIST_HPP_

#include <assert.h>
#include <iostream>
#include "LinkedList.h"
using namespace std;

/*
 * LISTNODE CONSTRUCTUORS AND FUNCTIONS
 */
ListNode::ListNode( int item ) {
    _item = item;
    _next = NULL;
}

void ListNode::printItem() {
    cout << _item;
}


/*
 * LIST CONSTRUCTORS AND FUNCTIONS
 */
List::List() {
    _head = NULL;
}

List::~List() {
    while ( _head ) {
        removeHead();
    }
}

void List::insertHead( int item ) {
    ListNode* newNode = new ListNode( item );
    newNode->_next = _head;
    _head = newNode;
}

int List::getHeadItem() {
    return _head->_item;
}

int List::removeHead() {
    int item = SHRT_MIN;  // -32768
    ListNode* temp;

    if ( _head ) {
        temp = _head;
        item = getHeadItem();
        _head = _head->_next;
        delete temp;
    }

    return item;
}

void List::reverse() {
    ListNode* curr = _head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while ( curr ) {
        next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }

    _head = prev;
}

void List::bubbleSort( bool printAtEveryIteration ) {

    // TODO: Implement bubble sort on this implementation of single linked list.
    //       Print the linked list after every pass in the outer iteration
    //       using print(false) function in List class if parameter is true.
    //       The list should be sorted in ascending order.

    // ENTER YOUR ANSWER BELOW.
    bool swapped = false;
    do {
        ListNode* temp1 = _head;
        ListNode* temp2 = _head->_next;
        ListNode* temp1tail = nullptr;
        swapped = false;
        while (temp1 && temp2) {
            if (temp1->_item > temp2->_item) {
                if (temp1tail == nullptr) {
                    //temp1tail null means must change head ptr
                    temp1->_next = temp2->_next;
                    temp2->_next = temp1;
                    _head = temp2;
                }
                else {
                    temp1->_next = temp2->_next;
                    temp2->_next = temp1;
                    temp1tail->_next = temp2;
                }
                swapped = true;
            }
            temp1tail = temp1;
            temp1 = temp2;
            temp2 = temp2->_next;
        }
        if (printAtEveryIteration) print(false);
    } while (swapped);


    // ENTER YOUR ANSWER ABOVE.
}

void List::mergeSort() {
    recursiveMergeSort( this );
}

void List::recursiveMergeSort( List* list ) {
    // TODO: Implement merge sort on this implementation of single linked list.
    // ENTER YOUR ANSWER BELOW.

    // Merge Sort: split, merge sort left, merge sort right, then merge together
    if (!list->_head || !list->_head->_next) return;
    // Return if only got 0 or 1 element, trivially sorted
    List* otherList = new List;
    list->split(otherList);
    recursiveMergeSort(list);
    recursiveMergeSort(otherList);
    list->merge(otherList);

    // ENTER YOUR ANSWER ABOVE.
}

void List::split( List* otherList ) {
    // TODO: Implement splitting of the current list.
    //       The first half of the list will be pointed by itself.
    //       The second half of the list will be pointed by otherList.
    //       It is guaranteed that the original list will have more than one node.
    //
    // ENTER YOUR ANSWER BELOW.
    ListNode* hare = _head; ListNode* tortoise = _head;
    if (!hare->_next) {
        otherList->_head = _head->_next;
        _head->_next = nullptr;
    }
    else {
        // Check hare->_next exists first. If not, might be infinite loop (in this case, for odd number item LL)
        while (hare->_next && hare->_next->_next && tortoise->_next) {
            hare = hare->_next->_next;
            tortoise = tortoise->_next;
        }
        otherList->_head = tortoise->_next;
        tortoise->_next = nullptr;
    }

    // ENTER YOUR ANSWER ABOVE.
}

void List::merge( List* otherList ) {
    // TODO: Implement merging of current list and otherList.
    //       The otherList should be empty after merging.
    //       It is guaranteed that both lists are non-empty.
    //
    // ENTER YOUR ANSWER BELOW.
    List* temp = new List;
    ListNode* list1ptr = _head;
    ListNode* list2ptr = otherList->_head;
    // Add smaller element in first, then reverse, because inserting from Head
    while (list1ptr && list2ptr) {
        if (list1ptr->_item < list2ptr->_item) {
            temp->insertHead(list1ptr->_item);
            list1ptr = list1ptr->_next;
            removeHead();
        }
        else {
            temp->insertHead(list2ptr->_item);
            list2ptr = list2ptr->_next;
            otherList->removeHead();
        }
    }
    // Append remaining list (assertion: either one list, but not both, to append)
    while (list1ptr) {
        temp->insertHead(list1ptr->_item);
        list1ptr = list1ptr->_next;
    }
    while (list2ptr) {
        temp->insertHead(list2ptr->_item);
        list2ptr = list2ptr->_next;
    }
    temp->reverse();
    assert(temp); // Optional, I guess
    _head = temp->_head;
    // ENTER YOUR ANSWER ABOVE.
}

void List::print( bool printWithNewLine = false ) {

    ListNode* curr = _head;

    while ( curr ) {
        cout << curr->_item;

        if ( printWithNewLine )
            cout << endl;
        else
            cout << " ";

        curr = curr->_next;
    }

    cout << endl;
}

#endif
