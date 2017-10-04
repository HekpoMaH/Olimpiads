/**
*	http://trekto.info/asd
*/

#include <iostream>
#include "hash.h"

using namespace std;

int main() {
	HashTable hashTable(5);
	hashTable.add(Student("0801561302", "Веселина", "Георгиева"));
	hashTable.add(Student("0801571303", "Наталия", "Бекриева"));
	hashTable.add(Student("0801581304", "Милена", "Кючюкова"));
	hashTable.add(Student("0801581305", "Димитър", "Димитров"));
	hashTable.add(Student("0801601306", "Ангел", "Титов"));
	hashTable.add(Student("0801611307", "Петко", "Петков"));

	cout<<"Хеш таблицата: \n" << hashTable << "\n";

	cout << "Търсене на 0801561302...\n";
	cout << hashTable.find("0801561302") << "\n\n";

	hashTable.remove("0801581305");
	hashTable.add(Student("0901911206", "Стефан", "Младенов"));

	cout << "Хеш таблицата: \n" << hashTable << "\n";

	hashTable.remove("0801581005");
	return 0;
	// тук се вика деструкторът на hashTable, който извиква деструкторите на всички списъци
}
