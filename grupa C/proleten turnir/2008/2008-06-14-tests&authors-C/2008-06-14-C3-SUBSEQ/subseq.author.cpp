#include <cstdio>
#include<iostream>
using namespace std;

int a[1048576],n,s,cn,i;
__int64 sum;

void solve()
{
	int f,l;
	f=l=0;
	sum=a[0];
	while(1)
	{
	  cout<<sum<<" "<<s<<endl;
		if(sum<=s)
		{
			if(sum==s)
			{
				cn++;
				sum-=a[f];
				f++;
			}
			else
			{
				l++;
				sum+=a[l];
			}
		}
		else
		{
			sum-=a[f];
			if(f==l)
			{
				l++;
				f++;
				sum+=a[l];
			}
			else f++;
		}
		if(l==n)break;
	}
}

int main()
{
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	solve();
	printf("%d\n",cn);
	return 0;
}
