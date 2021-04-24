#pragma once

#include <string>

using namespace std;


class Student {

private:
	string _name;
	double _cap;
	int _noOfModulesTaken;

public:
	Student() { _name = ""; _cap = 0; _noOfModulesTaken = 0; };
	Student(string, double, int);
	bool operator>(const Student&);
	bool operator==(const Student&);
	bool operator<(const Student&);
	string name() { return _name; };


	friend ostream &operator<<(ostream&, const Student&);

};

#include "Student.hpp"