#include<iostream>

using namespace std;
int a[1000001];
int main()
{
int s,n,i,j;
cin>>s>>n;
for(i=1;i<=n;i++)
 a[i]=1;
for(i=n+1;i<=s;i++)
{
a[i]=a[i-1]+1;
for(j=2;j<=n;j++)
{
if( (i%j==0) && (a[i/j]+1<a[i]) )
 a[i]=a[i/j]+1;
if(a[i-j]+1<a[i])
 a[i]=a[i-j]+1;
}
}
cout<<a[s]<<endl; 
return 0;
}
