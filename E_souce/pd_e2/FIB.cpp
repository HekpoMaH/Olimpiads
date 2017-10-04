#include<iostream>
using namespace std;
int main()
{int a1,a2,an,n,i;
cin>>n;
if(n==1)an=1;
if(n==2)an=1;
if(n==3)an=2;
if(n==4)an=3;
if(n==5)an=5;
if(n==6)an=8;
if(n==7)an=13;
if(n==8)an=21;
for(i=9;i<=n;i++)
{
               an=a1+a2;
               a1=a2;
               a2=an;
}
cout<<an<<"\n";      
return 0;
}
