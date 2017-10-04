/**
*	http://trekto.info/asd
*/

#include <iostream>
#include "student_list.h"

using namespace std;

class HashTable {
private:
	List* a;					// масив от списъци
	unsigned n;					// брой списъци

public:
	HashTable(unsigned n = 100) {			// конструктори
		this->n = n;
		cout << "hash start\n";
		a = new List[n];			// тук се извикват конструкторите на всички списъци от масива
		cout << "hash end\n";
	}
	
	~HashTable() {					// деструктор
		delete[] a;				// тук се извикват деструкторите на списъците
	}
	
	unsigned hash(string fn) {			// хеш функция
		unsigned sum = 0;
		for(int i = 0; i < fn.length(); i++) {
			sum += (i+1) * fn[i];
		}
		return sum % n;
	}

	void add(Student student) {			// добавя нов студент
		a[hash(student.fn)].add(student);
	}
	
	void remove(string fn) {			// премахва студента с ф.н. fn
		a[hash(fn)].remove(fn);
	}

	Student find(string fn) {			// намира и връща студента с ф.н. fn
		return (a[hash(fn)]).find(fn);
	}

	friend ostream &operator << (ostream &os, HashTable &aHashTable) {	// извежда hash таблицата
		os << "===================================\n";
		for(int i = 0; i < aHashTable.n; i++)
			os << i << ": \n" << aHashTable.a[i] << "\n";
		os << "===================================\n";
		return os;
	}
};