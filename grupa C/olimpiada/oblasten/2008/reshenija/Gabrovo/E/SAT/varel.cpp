#include<iostream>
using namespace std;
int main()
{long long N,V,K,a,c;
char b;
cin>>V>>K>>N;
for(a=0;a<N;a++)
{cin>>b;
if(b=='-')V=V-K;
else if(b=='+')V=V+K;
}
cout<<V<<endl;}
