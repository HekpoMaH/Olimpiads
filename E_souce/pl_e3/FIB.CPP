#include<iostream.h>
void main()
{int n;long a=1,p=0,b=p+a,c=0,br=0;
cin>>n;
if(n==1 || n==2)c=1;
if(n==3) c=2;
for(br=3;br<=n;br++)
{
c=a+b;a=c-a;b=c;}
cout<<c;}











