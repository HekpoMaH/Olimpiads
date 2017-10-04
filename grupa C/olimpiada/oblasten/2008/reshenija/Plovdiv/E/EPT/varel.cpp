#include<iostream>
using namespace std;
int main()
{
int i,v,k,n,m,br1,br2;
char a,b;
cin>>v;
cin>>k;
cin>>n;
for(i=0;i<=n;i++)
{
cin>>a>>b;
k=br1+br2;                
m=(v-(k*br1))+(k*br2);
}
cout<<m;
system ("pause");
return 0;
}
