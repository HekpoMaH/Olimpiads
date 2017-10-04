#include<iostream>
#include<fstream>
using namespace std;
ifstream iff;
ofstream of;
string a;
int main()
{
  iff.open("file1.txt");
  of.open("file2.txt");
  iff>>a;of<<a;
  return 0;
}
