#pragma once
#include <iostream>

using namespace std;

class Node {
private:
    int _data;
    Node* _lchild;
    Node* _rchild;
    int _height;
public:
    Node(int n) {
        _data = n;
        _lchild = nullptr;
        _rchild = nullptr;
        _height = 1;
    }
    int getData() { return _data; }
    friend class AVL;
};

class AVL {
public:
    Node* _root;
    AVL() { _root = nullptr; }
    ~AVL() { 
        if (_root) deleteTree(_root);
        cout << "Tree has been deleted successfully." << endl;
    }
    void deleteTree(Node* p);

    // Helper functions for inserting Node in AVL Tree
    int height(Node* p);
    int nodeHeight(Node* p);
    int balanceFactor(Node* p); // Check BF to determine rotation
    Node* LLRotation(Node* p); // Left child's left child causing imbalance
    Node* RRRotation(Node* p); // Right child's right child causing imbalance
    Node* LRRotation(Node* p); // Left child's right child causing imbalance
    Node* RLRotation(Node* p); // Right child's left child causing imbalance

    // Helper functions for deleting Node from AVL Tree
    Node* subtreeLargest(Node* p);
    Node* subtreeSmallest(Node* p);

    // Recursive Insert and Delete
    Node* rInsert(Node* p, int data);
    Node* rDelete(Node* p, int data);

    // Inorder traversal for ascending output (for testing)
    void inorder(Node* p);
    void inorder() { inorder(_root); } // just call tree->inorder() without parsing in root

    friend class Node;
};

int AVL::nodeHeight(Node* p) {
    // If p itself is nullptr, height should be 0, not 1
    if (p == nullptr)
        return 0;
    int hl, hr;
    hl = (p && p->_lchild) ? p->_lchild->_height : 0;
    hr = (p && p->_rchild) ? p->_rchild->_height : 0;
    return max(hl,hr)+1;
}

int AVL::balanceFactor(Node* p) {
    // If left subtree > right subtree, BF +ve
    // If right subtree > left subtree, BF -ve
    int hl, hr;
    // Cannot use nodeHeight function here, because if lchild/rchild does not exist,
    // we are accessing its height, which causes segfault
    hl = (p && p->_lchild) ? p->_lchild->_height : 0;
    hr = (p && p->_rchild) ? p->_rchild->_height : 0;
    return hl-hr;
}

// Single step rotation
Node* AVL::LLRotation(Node* p) {
    Node* pl = p->_lchild;
    Node* plr = pl->_rchild;

    pl->_rchild = p;
    p->_lchild = plr;
    
    // Since now pl is the centre element, and p is pl->_rchild, update heights
    // Update p height first, because pl's height depends on p
    p->_height = nodeHeight(p);
    pl->_height = nodeHeight(pl);

    // Change root to pl if p was root (rotations don't always happen around root)
    if (_root == p)
        _root = pl;
    return pl;
}

// Single step rotation
Node* AVL::RRRotation(Node* p) {
    Node* pr = p->_rchild;
    Node* prl = pr->_lchild;
    // pr will become centre element (from p)
    pr->_lchild = p;
    p->_rchild = prl;
    
    p->_height = nodeHeight(p);
    pr->_height = nodeHeight(pr);

    if (_root = p)
        _root = pr;
    return pr;
}

// Double step rotation
Node* AVL::LRRotation(Node* p) {
    Node* pl = p->_lchild;
    Node* plr = pl->_rchild;
    pl->_rchild = plr->_lchild;
    p->_lchild = plr->_rchild;
    plr->_lchild = pl;
    plr->_rchild = p;
    // Update heights
    // plr is root, and p and pl are its children, so update them first
    p->_height = nodeHeight(p);
    pl->_height = nodeHeight(pl);
    plr->_height = nodeHeight(plr);
    // If p was previously root
    if (_root = p)
        _root = plr;
    return plr;
}

// Double step rotation
Node* AVL::RLRotation(Node* p) {
    Node* pr = p->_rchild;
    Node* prl = pr->_lchild;
    pr->_lchild = prl->_rchild;
    p->_rchild = prl->_lchild;
    prl->_lchild = p;
    prl->_rchild = pr;
    // Update heights
    // prl is root, and p and pr are its children, so update them first
    p->_height = nodeHeight(p);
    pr->_height = nodeHeight(pr);
    prl->_height = nodeHeight(prl);
    // If p was previously root
    if (_root == p)
        _root = prl;
    return prl;
}

Node* AVL::rInsert(Node* p, int data) {
    // Base case, when p reaches a nullptr and you can insert into that spot
    if (p == nullptr) {
        Node* t = new Node(data);
        return t;
    }
    // Check if smaller or greater than centre element, decide path down tree
    // If smaller, store new node in left child of p (recursive call until p has no lchild)
    // If bigger, store new node in right child of p (recursive call until p has no rchild)
    if (data < p->_data)
        p->_lchild = rInsert(p->_lchild, data);
    else if (data > p->_data)
        p->_rchild = rInsert(p->_rchild, data);
    // Once new node is inserted, each node that was traversed in previous recursive call
    // will have new height
   
    p->_height = nodeHeight(p);

    // Checking for imbalance, and decision on rotation type at each of the traversed p
    if (balanceFactor(p) == 2 && balanceFactor(p->_lchild) == 1)
        return LLRotation(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->_lchild) == -1)
        return LRRotation(p);
    if (balanceFactor(p) == -2 && balanceFactor(p->_rchild) == -1)
        return RRRotation(p);
    if (balanceFactor(p) == -2 && balanceFactor(p->_rchild) == 1)
        return RLRotation(p);
    // If balanced
    return p;
}

Node* AVL::subtreeLargest(Node* p) {
    while (p && p->_rchild != nullptr)
        p = p->_rchild;
    return p;
}

Node* AVL::subtreeSmallest(Node* p) {
    while (p && p->_lchild != nullptr)
        p = p->_lchild;
    return p;
}


Node* AVL::rDelete(Node* p, int data) {
    // Cannot find key Node to delete
    if (p == nullptr)
        return nullptr;
    
    // If key Node is a leaf node
    if (p->_lchild == nullptr && p->_rchild == nullptr) {
        // Check if p IS the root, ie. only element in AVL Tree
        if (p == _root)
            _root = nullptr;
        delete p;
        return nullptr;
    }
    // Node is somewhere in the middle of the AVL Tree (not leaf)
    if (data < p->_data) 
        p->_lchild = rDelete(p->_lchild, data);
    else if (data > p->_data) 
        p->_rchild = rDelete(p->_rchild, data);
    else {
        // If this block is entered, we have reached Node to delete, 
        // but it is not a leaf
        Node* q;
        if (nodeHeight(p->_lchild) > nodeHeight(p->_rchild)) {
            // Left subtree > Right subtree, so we want to take from left sidetree after delete
            q = subtreeLargest(p->_lchild); // Finds largest element in left subtree
            p->_data = q->_data;
            p->_lchild = rDelete(p->_lchild, q->_data);
        }
        else {
            // Equal, or right subtree > left, so take from right subtree
            q = subtreeSmallest(p->_rchild);
            p->_data = q->_data;
            p->_rchild = rDelete(p->_rchild, q->_data);
        }
    }
        

    // Update height after delete
    p->_height = nodeHeight(p);

    // Balancing as done in Insertion
    if (balanceFactor(p) == 2 && balanceFactor(p->_lchild) == 1)
        return LLRotation(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->_lchild) == -1)
        return LRRotation(p);
    if (balanceFactor(p) == -2 && balanceFactor(p->_rchild) == -1)
        return RRRotation(p);
    if (balanceFactor(p) == -2 && balanceFactor(p->_rchild) == 1)
        return RLRotation(p);
    // Relevant because we might affect only right subtree, so left subtree still balanced
    if (balanceFactor(p) == 2 && balanceFactor(p->_lchild) == 0)
        return LLRotation(p);
    if (balanceFactor(p) == -2 && balanceFactor(p->_rchild) == 0)
        return RRRotation(p);

    return p;
}

void AVL::deleteTree(Node* p) {
    if (p == nullptr)
        return;
    deleteTree(p->_lchild);
    deleteTree(p->_rchild);
    delete p;
}

void AVL::inorder(Node* p) {
    if (p) {
        inorder(p->_lchild);
        cout << p->_data << " ";
        inorder(p->_rchild);
    }
}
