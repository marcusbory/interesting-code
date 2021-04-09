#include <bits/stdc++.h>
#include "AVLTrees.hpp"
using namespace std;

int main() {
    int arr[7] = { 10,20,30,25,28,27,5 };
    cout << "We will be inputting these outputs in this order into the AVL Tree: ";
    for (int j = 0; j < 7; j++)
        cout << arr[j] << " ";
    cout << endl;
    AVL* t = new AVL;
    for (int i = 0; i < 7; i++)
        t->_root = t->rInsert(t->_root, arr[i]);
    cout << "Inorder traversal of the AVL tree should give us sorted output: ";
    t->inorder();
    cout << endl;
    cout << "If insert was done on a normal binary tree, height of tree would be 6. With AVL tree, height is: " << t->nodeHeight(t->_root) << endl;
    cout << "The root is: " << t->_root->getData() << endl;

    cout << endl << "Let's attempt to delete." << endl;
    int del[4] = { 10, 20, 30, 25 };
    for (int k = 0; k < 4; k++) {
        t->rDelete(t->_root, del[k]);
        cout << "Deleted element: " << del[k] << endl;
        cout << "New root is: " << t->_root->getData() << endl;
        cout << "New height is: " << t->nodeHeight(t->_root) << endl << endl;
        //cout << "Inorder traversal: ";
        //t->inorder();
    }
    cout << "Inorder traversal of final tree: ";    
    t->inorder();
    cout << endl;
    cout << "New height of new AVL Tree is: " << t->nodeHeight(t->_root) << endl;
    delete t;
    return 0;
}
