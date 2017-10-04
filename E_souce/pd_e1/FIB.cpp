#include<iostream>
using namespace std;
int main ()
{
int n,s,a1,a2,i;
cin>>n;
if((a1=1)&&(a2=1)) s=1;
for(i=3;i<=n;i++)
{
s=a1+a2;
a1=a2;
a2=s;
}
cout<<s<<"\n";
return 0;
}
