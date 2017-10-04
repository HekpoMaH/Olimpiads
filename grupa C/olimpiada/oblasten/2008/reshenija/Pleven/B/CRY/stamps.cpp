#include<iostream>
#include<math.h>
using namespace std;
long s,n,a[5001],j,i,br,k,br1,m,b[5001],n1;

int main()
{
cin>>s>>n;
for(i=1;i<=n;i++)
{
                 cin>>b[i];
                 
a[b[i]]=1;
}
for(i=1;i<=s;i++)
{
 if(a[i]==0)
 { a[i]=10000; }
}
for(i=1;i<=s;i++)
for(j=i;j<=s-i;j++)
{
  br++;
 k=a[i]+a[j];
 if(a[i+j]>k)
 { a[i+j]=k; }
 
}
cout<<a[s];                

    return 0;
}
