#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define mn 50005
long n,m,a[mn],prime[mn];
long p[mn];
long is_prime(long x)
{
	long i,j;
	if(x==1)return 0;
	j=sqrt((double)x);
	for(i=2;i<=j;i++)
		if(x%i==0)
			return 0;
	return 1;
}
void solve()
{
	long i,j,br;
	scanf("%ld",&n);
	for(i=2;i<=n;i++)
		if(is_prime(i))
		{p[++p[0]]=i;prime[i]=1;}
	i=n+1;
	prime[0]=1;
	prime[1]=1;
	while(!is_prime(i))
		{i++;}
	m=i;
	a[0]=1;
	br=p[0];
	for(i=1;i<=br;i++)
		for(j=0;j+p[i]<=n;j++)
		{
			a[j+p[i]]+=a[j];
			a[j+p[i]]%=m;
		}
	if(prime[n])
		printf("%ld\n", a[n]-1);
	else
		printf("%ld\n", a[n]);
}
int main()
{
	solve();
	return 0;
}