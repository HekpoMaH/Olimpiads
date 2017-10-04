#include <iostream>

using namespace std;

int main() {
     
     unsigned long long a,b,c,x,y;

     cin>>a>>b;
     
     c=(a^b)>>1;
     x=c&~b;
     y=b|c;

     if(x+y!=a||(x^y)!=b)cout<<"-1"<<endl;
     else cout<<x<<" "<<y<<endl;

     return 0;
}
