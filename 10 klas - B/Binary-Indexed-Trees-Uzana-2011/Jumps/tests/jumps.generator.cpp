#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int n,b,seed;
string s;

ifstream fin("jumps.data.txt");
ofstream fout;

int main()
{ 
  fin >> s >> n >> b >> seed;
  while(fin.good())
  { cout << "jumps."+s+".in" << endl;
    fout.open(("jumps."+s+".in").c_str());
    if(s < "10")
    { fout << n << endl;
      srand(seed);
      for(int i=0; i<n; i++)  
      { int x,y;
        x = rand(); x = (x << 16) + rand();
        y = rand(); y = (x << 16) + rand();
        fout << x%b << " " << y%b << endl;
      } 
    }
    else
    { fout << 1000000 << endl;
      for(int i=0; i<100; i++) fout << "0 0" << endl;
      for(int i=100; i<200; i++) fout << "100 200" << endl;
      fout << "101 200" << endl; 
      for(int i=201; i<500; i++) fout << "200 200" << endl;
      for(int i=500; i<50000; i++) fout << i << " 200" << endl;
      fout << "500000 200" << endl; 
      for(int i=50001; i<1000000; i++) fout << "999999999 999999999" << endl; 
    }
      
    fout.close();
         
    fin >> s >> n >> b >> seed;
  }
  
  return 0;
}
