#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string c[20];
int n=5;
string mst;
int m;

int main(int argc, char *argv[])
{
 //  if (argc != 2)
 //  { cout << "Argument error" << endl;
 //    return 0;
 //  }

   ifstream fin(argv[2]);    // student's code.txt file

   if(fin.fail())
   { cout << 0 << endl;
     cout << "Wrong format" << endl;
     return 0;
   }

// Reading code.txt
   fin >> m;

   for(int i=1; i<=m; i++)
   {
     fin >> c[i];
     if(!fin.good())
     { cout << 0 << endl;
       cout << "Wrong format" << endl;
       return 0;
     }
   }


   for(int i=1; i<=m; i++)
   {
     if (c[i].length() !=5)
     {   cout << 0 << endl;
         cout << "Wrong format " << endl;
         return 0;
       }
     for(int j=0; j<n; j++)
       if(c[i][j]<'0' || c[i][j]>'2')
       { cout << 0 << endl;
         cout << "Wrong format "<< endl;
         return 0;
       }
   }



   cout << 1 << endl;
   cout << "Accepted" << endl;

   return 0;
}

