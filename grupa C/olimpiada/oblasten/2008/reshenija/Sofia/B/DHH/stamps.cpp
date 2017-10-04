#include <cstdio>
#include <algorithm>

using namespace std;

int s,n,a[3200],m,b[5400][3200];

bool f (int,int);
int stap (int,int);

int main ()
{
	scanf ("%d %d",&s,&n);
	int i,j;
	for (i=0;i<=s;i++)
	{
		for (j=0;j<=n;j++)
		{
			b[i][j]=-1;
		}
	}
	for (i=0;i<n;i++)
	{
		scanf ("%d",&a[i]);
	}
	sort (a,a+n,f);
	m=stap (s,0);
	printf ("%d\n",m);
	return 0;
}

bool f (int a,int b)
{
	return a>b;
}

int stap (int f,int k)
{
	if (a[n-2]>f || k==n-1) return f;
	int i,x=10000;
	for (i=k;i<n-1;i++)
	{
		if (a[i]<=f)
		{
			if (b[f][i]<0) b[f][i]=stap (f-a[i],i);
			if (x>b[f][i]) x=b[f][i];
		}
	}
	return x+1;
}
