/*
	Мышь всегда бежит к правому из ближайших сыру
*/

#include <cstdio>
#include <algorithm>

const int maxn=100001;
const int maxm=100001;
const int inf=1000000000;

int n,m,y0,y1,i,j;
int a[maxn],b[maxn],t[maxn],c[maxn];
int ans;
bool hasnext;

int main()
{
	freopen("mice.dat","r",stdin);
	freopen("mice.sol","w",stdout);
	scanf("%d%d%d%d",&n,&m,&y0,&y1);
	if(m==0)
	{
		printf("%d\n",n);
		return 0;
	}
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(i=0;i<m;i++)
	{
		t[i]=inf;
		c[i]=0;
	}
 	for(i=0,j=0;i<n;i++)
 	{
		while(j<m-1 && abs(b[j+1]-a[i])<=abs(b[j]-a[i])) j++;
		if(abs(b[j]-b[i])<t[j])
		{
			t[j]=abs(b[j]-b[i]);
			c[j]=0;
		}
		if(abs(b[j]-b[i])==t[j])
		{
			c[j]++;
		}
	}
	ans = n;
	for(i=0;i<m;i++)
		ans-=c[i];
	printf("%d\n",ans);
	return 0;
}
