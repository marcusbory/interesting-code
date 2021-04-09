// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "book.h"


#include "simpleLinkedListTemplate.h"
#include "Graph.h"

using namespace std;

template <class T>
bool List<T>::exist(T n) {

    return false;
}



// You should modify the following and submit

template <class T>
T List<T>::operator[](int idx)
{
    int ind = idx; _current = _head;
    while (ind--)
        _current = _current->_next;
    return _current->_item;
};

template <class T>
void List<T>::swap(int idx1, int idx2)
{
    T store;
    ListNode<T>* temp1 = _head;
    ListNode<T>* temp2 = _head;
    for (int i = 0; i < idx1; i++)
        temp1 = temp1->_next;
    store = temp1->_item;
    for (int ii = 0; ii < idx2; ii++)
        temp2 = temp2->_next;
    temp1->_item = temp2->_item;
    temp2->_item = store;
};


template <class T>
void SortedList<T>::sort()
{
    this->start(); int size = 0;
    while (!this->end()) {
        size++;
        this->next();
    }
    // Make use of idx1 and idx2 to track positions of elements
    // Use swap to implement bubble sort
    for (int i = 0; i < size; i++) {
        int idx1 = 0; int idx2 = 1; this->start();
        int j = size;
        while (j > 1) {
            T item1 = this->current();
            this->next();
            T item2 = this->current();
            if (item1 > item2)
                this->swap(idx1, idx2);
            j--; idx1++; idx2++;
        }
    }
};


int Graph::MST()
{
    
    return 0;

}
///////////////////////////////////////////////////////////////////
// Submission Zone Ended: You should submit your code above this line
///////////////////////////////////////////////////////////////////



void operatorTest();
void bookListTest();
void SortedListTest();
void bookSortedListTest();

int MSTTest(string,bool printGraph=true);



int main()
{
    
    
    operatorTest();
    //bookListTest();
    SortedListTest();
    //bookSortedListTest();
    //MSTTest("example1.txt");
    //MSTTest("example2.txt",false);
    //MSTTest("example3.txt", false);

    return 0;
}

void operatorTest() {
    cout << "Operator Test:" << endl;
    List<int> li;
    for (int i = 1; i <= 5; i++)
        li.insert(i*3+2);


    cout << "The list:" << endl;
    li.print();
    for (int i = 0; i < li.size(); i+=2)
        cout << "The item with index " << i << ":" << li[i] << endl;

    cout << "Swap position 1 and 3" << endl;
    li.swap(1, 3);
    li.print();
    cout << "Swap position 2 and 4" << endl;
    li.swap(2, 4);
    li.print();
    cout << endl;


}


void bookListTest()
{

    List<Book> lb;


    cout << "Book List Test:" << endl;

    for (int i = 5; i >0; i--)
    {
        string series("Hairy Border");
        
        Book b(series+to_string(i), 100 + i);
        lb.insert(b);
    }
    for (int i = 5; i > 0; i--)
    {
        string series("Bravo Super Hero Comics ");

        Book b(series + to_string(i), 23 + i);
        lb.insert(b);
    }

    cout << "First Book list" << endl;
    lb.print(true);
    cout << "After Swapping positions 2 and 7" << endl;
    lb.swap(7, 2);
    lb.print(true);
    cout << "After Swapping positions 3 and 4" << endl;
    cout << "After Swapping positions 0 and 5" << endl;
    lb.swap(3, 4);
    lb.print(true);
    lb.swap(5, 0);
    lb.print(true);
}


void SortedListTest() {
    cout << "Sorted List Test:" << endl;
    SortedList<int> sli;
    for (int i = 1; i <= 10; i++)
    {
        int n = (i * 23) % 13;
        cout << n << " is inserted" << endl;
        sli.insert(n);
        sli.print();
    }


    cout << "The sorted list:" << endl;
    sli.print();

    cout << endl;


}

void bookSortedListTest()
{

    SortedList<Book> slb;


    cout << "Sorted Book List Test:" << endl;
    for (int i = 5; i > 0; i--)
    {
        string series("Bravo Super Hero Comics ");

        Book b(series + to_string(i), 100 + 2*i);
        slb.insert(b);
    }
    for (int i = 5; i > 0; i--)
    {
        string series("Hairy Border");

        Book b(series + to_string(i), 101 + 2*i);
        slb.insert(b);
    }


    cout << "First Book list" << endl;
    slb.print(true);
}

int MSTTest(string filename, bool printGraph) {
    cout << "MST Test with file: " << filename << endl;
    ifstream myfile(filename);
    int v; // number of vertices
    int e; // number of edges


    if (myfile.fail()) {
        cout << "File not found" << endl;
        return -1;
    }

    myfile >> v;
    myfile >> e;



    Graph G(v); // create a graph with nv nodes
    int s, d, w;

    // read in all the edges and add into the graph
    for (int i = 0; i < e; i++)
    {
        myfile >> s;
        myfile >> d;
        myfile >> w;
        G.addEdge(s, d, w);
        G.addEdge(d, s, w);
    }

    if (printGraph)
        G.printGraph();


    cout << "The cost of MST = " << G.MST() << endl;
    myfile.close();
    cout << endl;
    return 0;
}