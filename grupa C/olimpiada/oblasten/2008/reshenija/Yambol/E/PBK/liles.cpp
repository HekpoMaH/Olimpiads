#include<iostream>
using namespace std;
int main()
{
long long sbor,max,N,i,j,pom,a[21];
max=0;
cin>>N;
for(i=1;i<=N;i++)
cin>>a[i];
for(i=N;i>1;i--)
for(j=1;j<N;j++)
if(a[j]>a[j+1])
{
pom=a[j];
a[j]=a[j+1];
a[j+1]=pom;
}
sbor=1;
for(j=2;j<=N;j++)
sbor=sbor+a[j];
cout<<sbor<<endl;
return 0;
}
