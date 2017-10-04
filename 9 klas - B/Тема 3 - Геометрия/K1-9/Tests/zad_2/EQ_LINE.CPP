// 
// eq_line checker
// check if two input lines are equal
// call: eq_line <juri's out-file> <competitor's out-file> <competitor's number>

#include<iostream>
#include<fstream>
using namespace std;

#include<string.h>
#define MAX 10000

fstream f;
char sj[MAX], sc[MAX];

int main(int argc, char *argv[])
{

 if(argc != 4) return 1;

 if(argv[3][0] != '0') cout << "\n" << argv[3] << " : ";

 f.open(argv[1],ios::in);
 f.getline(sj,MAX);
 f.close();

 while(sj[strlen(sj)-1]==' ') sj[strlen(sj)-1]=0;

 f.open(argv[2],ios::in);
 if(!f){cout << "MF "; return 9;}
 f.getline(sc,MAX);
 f.close();

 if(sc[0]==0) {cout << "WA "; return 1;}
 while(sc[strlen(sc)-1]==' ') sc[strlen(sc)-1]=0;


 if(strlen(sj) != strlen(sc)) {cout << "WA "; return 2;}

 for(int i=0; i<=strlen(sj); i++)
  if(sj[i] != sc[i]) {cout << "WA "; return 3;}

 cout << "OK ";
 return 0;
}

