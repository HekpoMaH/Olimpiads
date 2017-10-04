#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <ctime>
using namespace std;

int main(){
  double A[11]={1.23, 8, 500.9876, 2.4e5, 0.5, 100000.00001, 999.99999999, 2.71e6, 123456, 1, 0.0316227};
  char namein[50],namesol[50];
  ofstream fin, fsol;

  for (int i=0;i<11;i++) {
    sprintf(namein,"maxs.%02i.in",i);
    sprintf(namesol,"maxs.%02i.sol",i);
    fin.open(namein);
    fsol.open(namesol);
    fin << A[i] <<endl;
    fsol<< fixed<<setprecision(3)<<A[i]*A[i] << endl;
    fin.close();
    fsol.close();
  }

  return 0;
}
