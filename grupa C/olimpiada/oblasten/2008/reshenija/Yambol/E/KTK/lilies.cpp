#include<iostream>
using namespace std;
int main()
{

long long N,a[8],i,i2,br=0,p,i3,sim=0,p2;
cin>>N;
for (i=1;i<=N;i++)
cin>>a[i];
do
{   br=0;
	if (a[i]<a[i+1])
	{   
		p=a[i+1];
	a[i]=a[i+1];
	a[i+1]=a[i];
	br=1;
   }}
	while(br!=0);
	p2=N-1;
	do
	{
	sim=a[i]+a[i+1];
	i=i+2;
	p2=p2-2;
}
	while (p2>0);

cout<<sim;

    return 0;
}
