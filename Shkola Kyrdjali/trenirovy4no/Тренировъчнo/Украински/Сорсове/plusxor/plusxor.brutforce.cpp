#include <fstream>
#include <iostream>

using namespace std;

int main() {
     ifstream ifs("plusxor.dat");
     ofstream ofs("plusxor.sol");
     unsigned long long a,b,c,x,y,i,mx;

     ifs>>a>>b;
     
     x=0;y=0;
     for(i=0,mx=a/2;i<=mx;++i)
          if(i+(b^i)==a) {
               x=i;
               y=b^i;
               break;
          }

     if(x+y!=a||(x^y)!=b)ofs<<"-1"<<endl;
     else ofs<<x<<" "<<y<<endl;

     return 0;
}
