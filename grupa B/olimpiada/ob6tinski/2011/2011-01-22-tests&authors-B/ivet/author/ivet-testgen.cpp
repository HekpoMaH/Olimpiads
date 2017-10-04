#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cmath>
#include <ios>
#include <iomanip>

#define COUNT_TESTS 10

double a[COUNT_TESTS+1][2] = {
  {400,452.5},
  {217,300},
  {289,333},
  {385,444},
  {525,765},
  {601,707},
  {700,752},
  {777,844},
  {820,906},
  {863,950},
  {920,1000}
};

using namespace std;

int main(){

  char namein[50],namesol[50];
  ofstream fin, fsol;

  for (int i=0;i<=COUNT_TESTS;i++) {
    sprintf(namein,"../tests/ivet.%02i.in",i);
    sprintf(namesol,"../tests/ivet.%02i.sol",i);
    fin.open(namein);
    fsol.open(namesol);
    fin<<a[i][0]<<' '<<a[i][1]<<endl;
    fsol << fixed << setprecision (3) <<  (a[i][1]-a[i][0])/acos(-1)/14 << endl;
    fin.close();
    fsol.close();
  }

  return 0;
}
