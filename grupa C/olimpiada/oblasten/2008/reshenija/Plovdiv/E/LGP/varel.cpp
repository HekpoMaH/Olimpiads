#include<iostream>
using namespace std;
int main ()
{char c;int v,k,n,i;
cin>>v;
cin>>k;
cin>>n;
if(v<=1000 && k<=20)
{for(i=1;i<=n;i++)
{cin>>c;
if(c=='+')
v=v+k;
if(c=='-')
v=v-k;
}}
cout<<v<<endl;
return 0;
}
