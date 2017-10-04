#include <iostream>
using namespace std;
int main ()
{
int a,n,m,i,max,max1;
cin>>m>>n;
a=m+n;
max=m;
if(n>m)max=n;
for(;;max++)
if(max%m==0&&max%n==0)break;
max1=max;
for(;;max1=max1+max)
if(max1%a==0)break;
i=(max1/a)*2;
cout<<i<<endl;
return 0;
} 
