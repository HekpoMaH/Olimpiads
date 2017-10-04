#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=100001;
const int maxm=100001;
const int inf=1000000000;

int n,m,y0,y1,i;
int a[maxn],b[maxn];
int f[maxn][2];
int nearest[maxn][2],c[maxn];
int prev[maxn][2];

void findNearest()
{
	int i,j;
 	for(i=0,j=0;i<n;i++)
 	{
		while(j<m-1 && abs(b[j+1]-a[i])<abs(b[j]-a[i])) j++;
		nearest[i][0]=j;
		c[i]=1;
	    if(j<m-1 && abs(b[j+1]-a[i])==abs(b[j]-a[i]))
	    {
			j++;
	    	nearest[i][1]=j;
	    	c[i]=2;
		}else
		{
			nearest[i][1]=-1;
		}
	}
}

void findPrev()
{
	prev[0][0]=prev[0][1]=-1;
	for(i=1;i<n;i++)
	{
		if(nearest[i-1][1]!=-1 && nearest[i-1][1]!=nearest[i][0])
		{
			prev[i][0] = i-1;
			prev[i][1] = 1;
		}else
		if(nearest[i-1][0]!=nearest[i][0])
		{
			prev[i][0] = i-1;
			prev[i][1] = 0;
		}else
		{
			prev[i][0] = prev[i-1][0];
			prev[i][1] = prev[i-1][1];
		}
	}
}

int getf(int i,int j)
{
	if(i==-1) return 0;
	return f[i][j];
}

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
	findNearest();
	findPrev();
	f[0][0]=f[0][1]=0;
	int k,d1,d2;
	for(i=1;i<n;i++)
	{
		f[i][0]=inf;
		f[i][1]=inf;
		if(nearest[i][1]!=-1)
		{
			f[i][1] = f[i-1][1];
		}
		k = nearest[i][0];
		d1 = abs(a[i]-b[k]);
		d2 = abs(a[i-1]-b[k]);
		if(nearest[i-1][0]!=k && nearest[i-1][1]!=k || d1<d2 || d2<d1 && k==nearest[i-1][1])
		{
			f[i][0] = getf(prev[i][0],prev[i][1]) + i-1-prev[i][0];
		}else
		if(d1==d2 && k==nearest[i-1][1])
		{
			f[i][0] = getf(i-2,1);
		}else
		if(d1==d2 && k==nearest[i-1][0])
		{
			f[i][0] = getf(prev[i-1][0],prev[i-1][1]) + i-2-prev[i-1][0];
		}else
		{
			f[i][0] = f[i-1][1] + 1;
		}
		if(f[i][0]<f[i][1])
			f[i][1]=f[i][0];
	}
	printf("%d\n",f[n-1][1]);
	return 0;
}
