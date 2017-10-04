#include <iostream>

using namespace std;

int main() {
     
     unsigned long long a,b,x,y,i,mx;

     cin>>a>>b;
     
     x=0;y=0;
     for(i=0,mx=a/2;i<=mx;++i)
          if(i+(b^i)==a) {
               x=i;
               y=b^i;
               break;
          }

     if(x+y!=a||(x^y)!=b)cout<<"-1"<<endl;
     else cout<<x<<" "<<y<<endl;

     return 0;
}
