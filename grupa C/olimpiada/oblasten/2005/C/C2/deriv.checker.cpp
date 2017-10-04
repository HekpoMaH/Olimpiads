#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{

   if (argc != 4)
   { cout << "Argument error \n";
     return 0;
   }

/*
   ifstream fin(argv[1]);    // input file
   if(fin.fail())
   { cout << 0 << endl;
     cout << "Cannot open input file " << argv[1] << endl;
     return 0;
   }
*/

   ifstream fout(argv[2]);    // output file
   if(fout.fail())
   { cout << 0 << endl;
     cout << "Cannot open output file " << argv[2] << endl;
     return 0;
   }

   ifstream fsol(argv[3]);    // solution file
   if(fsol.fail())
   { cout << 0 << endl;
     cout << "Cannot open solution file " << argv[3] << endl;
     return 0;
   }

   int x, y;

   fout >> x;
   fsol >> y;

   if(x==y)
   { cout << 10 << endl;
     cout << "Correct solution \n";
   }
   else
   { cout << 0 << endl;
     cout << "Wrogn output \n";
     cout << x << " " << y << endl;
   }

   fout.close();
   fsol.close();


   return 0;
}

