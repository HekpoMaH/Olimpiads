#include <fstream>
#include <iostream>

using namespace std;

int main() {
     ifstream ifs("plusxor.dat");
     ofstream ofs("plusxor.sol");
     unsigned long long a,b,x,y;

     ifs>>a>>b;
     
     x=(a-b)/2;
     y=x+b;

     if(x+y!=a||(x^y)!=b)ofs<<"-1"<<endl;
     else ofs<<x<<" "<<y<<endl;

     return 0;
}
