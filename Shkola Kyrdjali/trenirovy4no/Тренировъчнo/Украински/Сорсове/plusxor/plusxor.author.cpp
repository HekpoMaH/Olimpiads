#include <fstream>
#include <iostream>

using namespace std;

int main() {
     ifstream ifs("plusxor.dat");
     ofstream ofs("plusxor.sol");
     unsigned long long a,b,c,x,y;

     ifs>>a>>b;
     
     c=(a^b)>>1;
     x=c&~b;
     y=b|c;

     if(x+y!=a||(x^y)!=b)ofs<<"-1"<<endl;
     else ofs<<x<<" "<<y<<endl;

     return 0;
}
