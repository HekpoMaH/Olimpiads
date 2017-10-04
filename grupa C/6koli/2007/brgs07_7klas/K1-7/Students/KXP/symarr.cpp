#include<iostream>
using namespace std;
int main()
{
int i,j,n,a[26][26];
cin>>n;
bool p=0;
for(i=1;i<=n;i++)for(j=1;j<=n;j++)
{
cin>>a[i][j];
if(i+j>=n+2 && a[i][j]!=a[n+1-j][n+1-i])p=1;
}
if(p)
{
long sum=0;
for(i=1;i<=n;i+=2)for(j=1;j<=n;j++)sum+=a[i][j];
cout<<sum<<endl;
}
else
{
for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j] && !(a[i][j]%3))cout<<a[i][j]<<' ';
cout<<endl;
}
}
