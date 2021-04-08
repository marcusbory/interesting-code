#include "Student.h"
#ifndef STUDENTH
#define STUDENTH

#include <iostream>

#pragma once


Student::Student(string name, double cap, int noOfMods) {

	_name = name;
	_cap = cap;
	_noOfModulesTaken = noOfMods;

}
bool Student::operator>(const Student& s) {
	if (_cap > s._cap)
		return true;
	if (_cap == s._cap && _noOfModulesTaken > s._noOfModulesTaken)
		return true;
	if (_cap == s._cap && _noOfModulesTaken == s._noOfModulesTaken && _name > s._name)
		return true;
	return false;
}

bool Student::operator==(const Student& s) {
	return (_cap == s._cap && _noOfModulesTaken == s._noOfModulesTaken && _name == s._name);
}

bool Student::operator<(const Student& s) {
	if (_cap < s._cap)
		return true;
	if (_cap == s._cap && _noOfModulesTaken < s._noOfModulesTaken)
		return true;
	if (_cap == s._cap && _noOfModulesTaken == s._noOfModulesTaken && _name < s._name)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Student& f)
{
	os << "|| Name: " << f._name << " CAP: " << f._cap << " No Of Modules: " << f._noOfModulesTaken;

	return os;
}


#endif