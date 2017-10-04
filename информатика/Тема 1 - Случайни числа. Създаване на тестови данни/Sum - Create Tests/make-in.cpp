#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main()
{ 
    ifstream ifile;
    ifile.open  ("TestNumbers.txt");
    string s;
    ofstream ofile;
    srand (time(NULL));
    while (ifile >>s)
    {
        ofile.open (("Sum."+s+".in").c_str());
        int n = rand()%100;
        ofile << n << endl;
        for (int i = 1; i < n ; i++)
        ofile << rand()<< " ";
        ofile << endl;
        ofile.close();
    }  
    ifile.close();      
    return 0;
}
