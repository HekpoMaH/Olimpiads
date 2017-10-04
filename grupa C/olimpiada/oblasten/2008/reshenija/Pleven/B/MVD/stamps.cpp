/* suma s min br elementi*/
#include<iostream>
#include<stdio.h>
using namespace std;
long long a[3002],f[5002];
long long i,s,min1,k,n,r;
int main()
{
cin>>s>>r;
for(i=1;i<=r;i++)
 scanf("%d",&a[i]);
 sort(a,a+r+1);

for(i=1;i<=s;i++)
{ min1=2000000000;
for(k=1;k<=r;k++)
 if(a[k]<=i)
  if(f[i-a[k]]<min1)
  min1=f[i-a[k]];
f[i]=min1+1;
}
cout<<f[s]<<endl;
// system("PAUSE");
return 0;
}
