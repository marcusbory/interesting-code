#include "BST.h"
#include "Student.h"

#include <iostream>
using namespace std;


Student stu1("John", 3.2, 19);
Student stu2("Andy", 4.2, 2);
Student stu3("Joseph", 4.9, 32);
Student stu4("Tzerbin", 5.0, 21);
Student stu5("Dezhang", 1.0, 33);

//rank by modules, sameCap2>sameCap1
Student sameCap1("SameCap1", 4.0, 2);
Student sameCap2("SameCap2", 4.0, 28);

//rank by name, 2>1
Student sameCapSameModule1("SameCapSameModule1", 4.0, 28);
Student sameCapSameModule2("SameCapSameModule2", 4.0, 28);

//both the same 
Student identical1("Identical", 5, 10);
Student identical2("Identical", 5, 10);


void testInsertStudentAllUnique();
void testInsertStudentSameCap();
void testInsertStudentSameCapSameModule();
void testIdenticalStudents();
void testRankStudent();
void testRankInteger() {
	BinarySearchTree<int> bst;
	for (int i = 0; i < 10; ++i) {
		bst.insert(i * 2);
	}
	cout << "Size of tree is " << bst.size() << endl;
	cout << "PreOrder: " << endl;
	bst.preOrderPrint();
	cout << "InOrder: " << endl;
	bst.inOrderPrint();
	cout << "PostOrder: " << endl;
	bst.postOrderPrint();
	for (int i = 0; i < 13; i++) {
		cout << "rank of node containing " << i * 2 << " is " << bst.rank(i * 2) << endl;
	}
}


int main() {
	testRankInteger();
	cout << endl << endl;

	testInsertStudentAllUnique();
	testInsertStudentSameCap();
	testInsertStudentSameCapSameModule();
	testIdenticalStudents();

	testRankStudent();

}
void testInsertStudentAllUnique() {

	BinarySearchTree<Student> bst;

	bst.insert(stu1);
	bst.insert(stu2);
	bst.insert(stu3);
	bst.insert(stu4);
	bst.insert(stu5);

	cout << "The size of the tree is " << bst.size() << endl;

	cout << "Pre-order Traversal:" << endl;
	bst.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bst.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bst.postOrderPrint();

	cout << endl;
	cout << endl;

}
void testInsertStudentSameCap() {

	cout << "Inserting Into Empty Tree" << endl;
	BinarySearchTree<Student> bst;
	bst.insert(sameCap1);
	bst.insert(sameCap2);

	cout << "The size of the tree is " << bst.size() << endl;

	cout << "Pre-order Traversal:" << endl;
	bst.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bst.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bst.postOrderPrint();

	cout << endl;
	cout << endl;


	cout << "Inserting Into Non - Empty Tree" << endl;
	BinarySearchTree<Student> bsts;

	bsts.insert(stu1);
	bsts.insert(stu2);
	bsts.insert(stu3);
	bsts.insert(stu4);
	bsts.insert(stu5);


	bsts.insert(sameCap1);
	bsts.insert(sameCap2);

	cout << "The size of the tree is " << bsts.size() << endl;

	cout << "Pre-order Traversal:" << endl;
	bsts.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bsts.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bsts.postOrderPrint();

	cout << endl;
	cout << endl;

}
void testInsertStudentSameCapSameModule() {

	cout << "Inserting Into Empty Tree" << endl;
	BinarySearchTree<Student> bst;
	bst.insert(sameCapSameModule1);
	bst.insert(sameCapSameModule2);

	cout << "The size of the tree is " << bst.size() << endl;

	cout << "Pre-order Traversal:" << endl;
	bst.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bst.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bst.postOrderPrint();

	cout << endl;
	cout << endl;


	cout << "Inserting Into Non - Empty Tree" << endl;
	BinarySearchTree<Student> bsts;

	bsts.insert(stu1);
	bsts.insert(stu2);
	bsts.insert(stu3);
	bsts.insert(stu4);
	bsts.insert(stu5);


	bsts.insert(sameCapSameModule1);
	bsts.insert(sameCapSameModule2);

	cout << "The size of the tree is " << bsts.size() << endl;

	cout << "Pre-order Traversal:" << endl;
	bsts.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bsts.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bsts.postOrderPrint();

	cout << endl;
	cout << endl;
}
void testIdenticalStudents() {

	cout << "Test if == operator works for 2 identical students" << endl;
	if (identical1 == identical2) {
		cout << "== operator works" << endl;
	}

	else {
		cout << "== operator does not work" << endl;
	}

	cout << "Test if == works for non identical students" << endl;

	if (identical1 == stu5) {
		cout << "== operator does not work" << endl;
	}
	else {
		cout << "== operator works" << endl;
	}


	cout << endl << endl;
}

void testRankStudent() {

	BinarySearchTree<Student> bsts;

	Student arr[] = { stu1, stu2, stu3, stu4, stu5, sameCap1, sameCap2, sameCapSameModule1, sameCapSameModule2 };

	for (Student s : arr) {
		bsts.insert(s);
	}

	cout << "In-order Traversal:" << endl;
	bsts.inOrderPrint();

	for (Student s : arr) {
		cout << s.name() << "'s rank = " << bsts.rank(s) << endl;;

	}

	cout << endl << endl;


}