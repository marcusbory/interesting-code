#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
public:
    // Setting first node as public so that I can pass it into my merge function later
    Node* first;
    LinkedList();
    LinkedList(int* arr, int numOfElem);
    ~LinkedList();

    int length();
    void display();
    bool isSorted();
};

Node* mergeList(Node* p, Node* q);

int main()
{
    int arrA[3] = { 2,3,7 };
    int arrB[3] = { 4,8,10 };
    LinkedList* a = new LinkedList(arrA, 3);
    LinkedList* b = new LinkedList(arrB, 3);
    cout << "Linked List A is ";
    a->isSorted();
    cout << "Linked List B is ";
    b->isSorted();
    LinkedList* merged = new LinkedList;
    merged->first = mergeList(a->first, b->first);
    merged->display();
    cout << "The merged list is ";
    merged->isSorted();
    delete a, b, merged;
}

LinkedList::LinkedList()
{
    first = NULL;
}

LinkedList::LinkedList(int* arr, int numOfElem)
{
    Node* t, * last;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < numOfElem; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node* p;
    while (first != NULL)
    {
        p = first;
        first = first->next;
        delete p;
    }
}

void LinkedList::display()
{
    Node* p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::length()
{
    int count = 0;
    Node* p = first;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool LinkedList::isSorted()
{
    int x = INT32_MIN;
    Node* p = first;
    while (p != NULL)
    {
        if (p->data < x)
        {
            cout << "Not sorted" << endl;
            return false;
        }
        x = p->data;
        p = p->next;
    }
    cout << "Sorted" << endl;
    return true;
}

Node* mergeList(Node* p, Node* q)
{
    Node* merged = NULL, * last = NULL;
    if (p->data < q->data)
    {
        merged = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        merged = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
    return merged;
}