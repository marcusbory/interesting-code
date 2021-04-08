#pragma once
#ifndef BSTHPP
#define BSTHPP
#include "BST.h"

template <class T>
void TreeNode<T>::rectifyHeight()
{
	int left = _left ? _left->_height : -1;
	int right = _right ? _right->_height : -1;
	_height = (left > right ? left : right) + 1;
}

template <class T>
void BinarySearchTree<T>::insert(T x)
{
	if (_root) {
		_root = _insert(_root, x);
	}
	else {
		_root = new TreeNode<T>(x);
		_size++;
	}
	//_root = _root ? _insert(_root, x) : new TreeNode<T>(x);
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMax(TreeNode<T>* current) {
	while (current->_right)
		if (current->_right->_right)
			current = current->_right;
		else
			return current->_right;
	return current;
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMin(TreeNode<T>* current) {
	while (current->_left)
		if (current->_left->_left)
			current = current->_left;
		else
			return current->_left;
	return current;
}

template <class T>
T BinarySearchTree<T>::successor(T x)
{
	TreeNode<T>* node = _search(_root, x);

	if (node->_item > x)
		return node->_item;

	if (node->_right)
		return _searchMin(node->_right)->_item;
	else {
		TreeNode<T>* current = _root;
		TreeNode<T>* lastParent = NULL;

		while (current) {

			if (x > current->_item)
			{
				if (current->_right)
					current = current->_right;
				else
					current = NULL;
			}
			else  {
				if (current->_left)
				{
					lastParent = current;
					current = current->_left;
				}
				else
					current = NULL;
			}
		}

		return lastParent->_item;

	}
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_search(TreeNode<T>* current, T x) {

	while (current) {
		if (current->_item == x)
			return current;
		else if (x > current->_item)
		{
			if (current->_right)
				current = current->_right;
			else
				return current;
		}
		else {
			if (current->_left)
				current = current->_left;
			else
				return current;
		}

	}

	return NULL;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {


	if (current->_item > x)
	{
		if (current->_left)
			current->_left = _insert(current->_left, x);
		else
		{
			current->_left = new TreeNode<T>(x);
			_size++;
		}
	}
	else if (x > current->_item) {
		if (current->_right)
			current->_right = _insert(current->_right, x);
		else
		{
			current->_right = new TreeNode<T>(x);
			_size++;
		}
	}
	else
		return current;



	int left = current->_left ? current->_left->_height : -1;
	int right = current->_right ? current->_right->_height : -1;
	current->_height = (left > right ? left : right) + 1;

	if (abs(left - right) > 1)
	{


		if (left > right)
		{

			int LLH = current->_left->_left ? current->_left->_left->_height : 0;
			int LRH = current->_left->_right ? current->_left->_right->_height : 0;
			if (LLH < LRH)
				current->_left = _leftRotation(current->_left);
			current = _rightRotation(current);
		}
		else {

			int RLH = current->_right->_left ? current->_right->_left->_height : 0;
			int RRH = current->_right->_right ? current->_right->_right->_height : 0;
			if (RRH < RLH)
				current->_right = _rightRotation(current->_right);
			current = _leftRotation(current);

		}
	}


	current->rectifyHeight();

	return current;

}

template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};

template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
	TreeNode<T>* r = node->_right;
	node->_right = r->_left;
	r->_left = node;
	node->rectifyHeight();
	r->rectifyHeight();
	return r;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
	TreeNode<T>* r = node->_left;
	node->_left = r->_right;
	r->_right = node;
	node->rectifyHeight();
	r->rectifyHeight();
	return r;
}

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}


template <class T>
void BinarySearchTree<T>::inOrderPrint() {

	_inOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_inOrderPrint(node->_left);
	cout << node->_item << " ";
	_inOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::preOrderPrint() {

	_preOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::postOrderPrint() {

	_postOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_postOrderPrint(node->_left);
	_postOrderPrint(node->_right);
	cout << node->_item << " ";
}

template <class T>
int BinarySearchTree<T>::rank(T item) {
	if (!exist(item))
		return -1;
	int rank = recursiveRank(_root, item);
	return rank;
}
//if you define other helper functions, please include them here. 

template <class T>
int BinarySearchTree<T>::recursiveRank(TreeNode<T>* node, T item) {
	if (!node) return 0;
	if (node->_item == item)
		return subtreeSize(node->_left);
	if (node->_item > item)
		return recursiveRank(node->_left, item);
	return subtreeSize(node->_left) + 1 + recursiveRank(node->_right, item);
}

template <class T>
int BinarySearchTree<T>::subtreeSize(TreeNode<T>* node) {
	if (!node) 
		return 0;
	return subtreeSize(node->_left) + 1 + subtreeSize(node->_right);
}

// END OF MY OWN HELPER FUNCTIONS

template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}

#endif