#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <ctime>
using namespace std;

char names[11][40] = {"richmensgames.000.in",
    "richmensgames.001.in","richmensgames.002.in","richmensgames.003.in","richmensgames.004.in","richmensgames.005.in",
    "richmensgames.006.in","richmensgames.007.in","richmensgames.008.in","richmensgames.009.in","richmensgames.010.in"
};


int main() {

  ofstream f;
  int i, j;

  srand(time(NULL));
                      //   ( бр.купчини    банката)
  // richmensgames.000.in       (5,      20 )
  f.open(names[0]);
  f<<"3   10 7\n  \n    7      12\n20\n";
  f.close();

  // richmensgames.001.in        ( 1 , 2 147 483 647 )
  f.open(names[1]);
  f<<1<<"     "<<INT_MAX<<"\n";
  f.close();

  // richmensgames.002.in        ( 258,   100 000 )
  f.open(names[2]);
  for (i=1; i<258; i++) f<<800-i<<"     ";
  f<<100000<<"\n";
  f.close();

  // richmensgames.003.in        ( 416 000,   999 999 999  )
  f.open(names[3]);
  for (j=0; j< 1000; j++) for (i=1; i<417; i++) f<<689-i<<"     ";
  f<<999999999<<"\n";
  f.close();

  // richmensgames.004.in        (  1 080 216,   1  )
  f.open(names[4]);
  for (j=0; j< 5001; j++) for (i=1; i<217; i++) f<<689-i<<"     ";
  f<<1<<"\n";
  f.close();

  // richmensgames.005.in     ( 1 500 000, 576 123 456 )
  f.open(names[5]);
  for (j=0; j< 1500000; j++) f<<689-i<<"     ";
  f<<  576123456   <<"\n";
  f.close();

  // richmensgames.006.in      (3 000 000,   2 147 483 647  )
  f.open(names[6]);
  for (j=0, i=382; j< 3000000; j++)  { i %=1000;i++; f<<i<<"\n";}
  f<<   INT_MAX  <<"\n";
  f.close();

  // richmensgames.007.in       (4 000 000, 8 000 000 )
  f.open(names[7]);
  for (j=0, i=rand()%100+1; j< 4000000; j++) { f<<i<<"\n\n";}
  f<<  8000000   <<"\n";
  f.close();

  // richmensgames.008.in        ( 6 000 000, rand()
  f.open(names[8]);
  for (j=0, i=1000; j< 6000000; j++) { f<<i--<<" "; if (i==0) i = 1000;}
  f<<   rand()+1  <<"\n";
  f.close();

  // richmensgames.009.in        ( 8 000 000, rand()
  f.open(names[9]);
  for (j=0, i=999; j< 8000000; j++) { f<<i--<<" "; if (i==0) i = 1000;}
  f<<   rand()+1  <<"\n";
  f.close();

  // richmensgames.010.in        ( 10 000 000, 2 147 483 647 )
  f.open(names[10]);
  for (j=0; j< 10000000; j++) f<<rand()%1000+1<<" ";
  f<<   INT_MAX  <<"\n";
  f.close();

  return 0;

}
