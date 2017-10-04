#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
   cin>>a>>b>>c;
   int val,mx=0;
   val=a+b+c;
   mx=max(val,mx);
   val=a*b+c;
   mx=max(val,mx);
   val=a+b*c;
   mx=max(val,mx);
   val=(a+b)*c;
   mx=max(val,mx);
   val=a*(b+c);
   mx=max(val,mx);
   val=a*(b*c);
   mx=max(val,mx);
   cout<<mx<<"\n";
}
