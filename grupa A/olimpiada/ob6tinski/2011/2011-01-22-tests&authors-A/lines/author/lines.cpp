#include <iostream>
#include <list>

using namespace std;

struct line{
	int a,b,c;
};
typedef list<line> lineList;	//list of lines
lineList lineClasses[1000];		//array of different classes of lines
int n = 0;						//number of elements in the array

bool sameClass(line, line);		//checks if two lines are in the same class
bool eqLines(line, line);		//checks if two lines of the same class
								// are equal
bool isInList(list<line>, line);	//check if the line is in the list
void read();					//reads and stores the input data
int calcDiff();					//calculates the number of different lines

int main(){
	read();
	cout << calcDiff() << endl;
	cout << n << endl;
	return 0;
}

//checks if two lines are in the same class
bool sameClass(line l1, line l2){
	return l1.a*l2.b == l2.a*l1.b;
}		

//checks if two lines of the same class
// are equal
bool eqLines(line l1, line l2){
	return (l1.a*l2.c == l2.a*l1.c)  && (l1.b*l2.c == l2.b*l1.c);
}	


bool isInList(list<line> lst, line l){
	lineList::iterator lst_iter;
	for (lst_iter = lst.begin(); lst_iter != lst.end(); lst_iter++)
		if (eqLines(*lst_iter, l))
			return true;
	return false;
}

void read(){
	
	line l;
	int N;

	cin >> N;
	cin >> l.a >> l.b >> l.c;
	lineClasses[0].push_back(l); n++;

	for (int i=1; i<N; i++){
		cin >> l.a >> l.b >> l.c;
		int j;
		for (j = 0; (j < n) && !sameClass(l, lineClasses[j].front()); j++);
		if (!isInList(lineClasses[j],l))
			lineClasses[j].push_back(l);
		if (j==n) n++;					//new class
	}

}

int calcDiff(){
	int cnt = 0;
	for (int i=0; i<n; i++)
		cnt += lineClasses[i].size();
	return cnt;
}