#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=100001;
const int maxm=100001;
const int inf=1000000000;

int n,m,y0,y1,i;
int a[maxn],b[maxn];
int nearest[maxn][2],c[maxn];
int ans;
int dist[maxm];

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

void Search(int d,int cur)
{
	if(d==n)
	{
		if(cur<ans)
			ans=cur;
	}else
	if(cur-(n-d)<ans)
	{
		int n0 = nearest[d][0];
		int n1 = nearest[d][1];
		int curd = abs(b[n0]-a[d]);
		int tempd;
		if(dist[n0]==inf || dist[n0]==curd)
		{
			tempd = dist[n0];
			dist[n0] = curd;
			Search(d+1,cur-1);
			dist[n0] = tempd;
		}
		if(n1!=-1 && (dist[n1]==inf || dist[n1]==curd))
		{
			tempd = dist[n1];
			dist[n1] = curd;
			Search(d+1,cur-1);
			dist[n1] = tempd;
		}
		Search(d+1,cur);
	}
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
	ans = n;
	for(i=0;i<m;i++)
		dist[i]=inf;
	Search(0,n);
	printf("%d\n",ans);
	return 0;
}
