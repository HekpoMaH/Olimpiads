#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string c[20];
int n=5;
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
     cout << "Cannot open file" << endl;
     return 0;
   }

// Reading code.txt
   fin >> m;
   if(m<2 || m>18)
   {   cout << 0 << endl;
       cout << "Wrong answer" << endl;
       return 0;
   }

   for(int i=1; i<=m; i++)
   {
     fin >> c[i];
     if(!fin.good())
     { cout << 0 << endl;
       cout << "Error reading code.txt" << endl;
       return 0;
     }
   }


   for(int i=1; i<=m; i++)
     for(int j=0; j<n; j++)
       if(c[i][j]<'0' || c[i][j]>'2')
       { cout << 0 << endl;
         cout << "Wrong word " << i << endl;
         return 0;
       }

   for(int i1=1; i1<m; i1++)
   for(int i2=i1+1; i2<=m; i2++)
   { int d=0;
     for(int j=0; j<n; j++)
       if(c[i1][j] != c[i2][j]) d++;
     if(d<3)
       { cout << 0 << endl;
         cout << "Wrong distance " << i1 << " " << i2 << endl;
         return 0;
       }
   }



   int pnts = m*m / 324.0 * 100;
   cout << pnts << endl;
   cout << "Accepted" << endl;

   return 0;
}

