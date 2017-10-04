/**
*	http://trekto.info/asd
*/

#include <iostream>
#include <string>
#include <cstdlib>				// нужна за използване на exit()
#include "student.h"				// описва класа Student

using namespace std;

struct Elem {
	Student data;				// данни
	Elem* next;				// указател към следващия елемент
};

class List {
private:
	Elem* pStart;				// указател към началото на списъка
	void copyList(const List &aList);	// помощен метод за копиране на списъка

public:
	List();					// конструктор по подразбиране
	List(const List &aList);		// копиращ конструктор
	~List();				// деструктор
	void add(Student aData);		// добавя студент
	void remove(string fn);			// премахва студента с ф.н. fn
	Student find(string fn);		// намира и връща студента с ф.н. fn
	void removeAll();			// премахва всички елементи от списъка
	List &operator = (const List &aList);	// оператор за присвояване
	friend ostream &operator << (ostream &os, List &aList) {	// оператор за извеждане
		Elem* p = aList.pStart;
		while(p) {
			os << p->data << '\n';
			p = p->next;
		}
		return os;
	}
};

void List:: add(Student aData) {		// добавя студент
	Elem* temp = new Elem;			// заделяме памет за новия елемент
	temp->data = aData;			// копираме в него данните
	temp->next = pStart;			// насочваме 'следващия' му към стария първи елемент
	pStart = temp;				// правим новия елемент първи
}

Student List:: find(string fn) {		// намира и връща студента с ф.н. fn
	Elem* p = pStart;			// насочваме указател за обхождане към началото
	while(p && p->data.fn != fn)		// докато списъкът не е свършил и не е намерен студентът
		p = p->next;			// преминаваме към следващия студент

	if(!p) {				// ако списъкът свърши преди да сме намерили студента
		cerr << "Няма студент с ф.н.: " << fn << "!\n\n";
		exit(1);
	}

	return p->data;				// връщаме студента
}

void List:: remove(string fn) {			// премахва студента с ф.н. fn
	if(!pStart) {				// ако списъкът е празен
		cerr << "Няма студент с ф.н.: " << fn << "!\n\n";
		exit(1);
	}

	if(fn, pStart->data.fn == fn) {	// ако студентът е в началото на списъка
		Elem* temp = pStart;		// насочваме помощен указател към първия елемент
		pStart = pStart->next;		// насочваме началото към 'следващия' му
		delete temp;			// изтриваме първия
		return;
	}

	Elem* p = pStart;			// насочваме указател за обхождане към началото
	while(p->next && p->next->data.fn != fn)	// докато списъкът не е свършил
							// и не е намерен студентът
		p = p->next;				// преминаваме към следващия студент

	if(!p->next) {				// ако списъкът свърши преди да сме намерили студента
		cerr << "Няма студент с ф.н.: " << fn << "!\n\n";
		exit(1);
	}

	// щом сме стигнали до тук p трябва да сочи към студента преди този с ф.н. fn
	Elem* temp = p->next;			// насочваме временен указател към ел. който ще премахваме
	p->next = p->next->next;		// премахваме елемента от списъка
	delete temp;				// и го изтриваме
}

List:: List() {
	pStart = NULL;
}

List:: List(const List &aList) {
	pStart =  NULL;
	copyList(aList);
}

List:: ~List() {
	removeAll();
}

void List:: copyList(const List &aList) {
	Elem* p = aList.pStart;
	while(p) {
		add(p->data);
		p = p->next;
	}
}

List &List:: operator = (const List &aList) {
	if(this != &aList) {
		removeAll();
		copyList(aList);
	}
	return *this;
}

void List:: removeAll() {
	Elem* temp;
	while(pStart) {
		temp = pStart;
		pStart = pStart->next;
		delete temp;
	}
}