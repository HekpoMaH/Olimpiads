#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
   cin>>n;
   int m=1,t;
   while(m<=n)m*=2;
   cout<<"A";
   if(n&1)t=m/2+1;
   else t=m/4+2;
   for(int i=2;i<=t;i++)cout<<"B";
   cout<<"\n";
   for(int i=1;i<=m-n;i++)cout<<2;
   for(int i=1;i<=n-m/2;i++)cout<<21;
   cout<<"\n";
}
