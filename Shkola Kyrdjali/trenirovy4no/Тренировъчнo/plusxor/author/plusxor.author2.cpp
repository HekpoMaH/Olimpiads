#include <iostream>

using namespace std;

int main() {
     
     unsigned long long a,b,x,y;

     cin>>a>>b;
     
     x=(a-b)/2;
     y=x+b;

     if(x+y!=a||(x^y)!=b)cout<<"-1"<<endl;
     else cout<<x<<" "<<y<<endl;

     return 0;
}
