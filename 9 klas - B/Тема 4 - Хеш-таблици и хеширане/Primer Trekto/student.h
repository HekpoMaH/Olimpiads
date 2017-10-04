/**
*	http://trekto.info/asd
*/

#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	string fn;
	string firstName;
	string lastName;

	Student() {
	}

	Student(string fn, string firstName, string lastName) {
		this->fn = fn;
		this->firstName = firstName;
		this->lastName = lastName;
	}

	friend ostream &operator << (ostream &os, const Student &aStudent) {
		os << aStudent.fn << " - " << aStudent.firstName << " " << aStudent.lastName;
		return os;
	}
};