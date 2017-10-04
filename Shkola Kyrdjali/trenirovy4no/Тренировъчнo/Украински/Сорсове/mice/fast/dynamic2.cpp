#pragma comment(linker,"/STACK:100000000")

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int maxn=100001;
const int maxm=100001;
const int inf=1000000000;

typedef pair<int,int> pii;

int n,m,y0,y1,i;
int a[maxn],b[maxn];
map<pii,int> f;
int nearest[maxn][2],c[maxn];

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

int calc(int i,int j)
{	
	if(j<=-1)return i+1;
	if(i<=-1)return 0;
	pii cur = pii(i,j);
	if(f.count(cur)==1)
		return f[cur];
	if(nearest[i][0]>j)
	{
		f[cur] = calc(i-1,j)+1;
	}else
	if(c[i]==2 && nearest[i][1]<=j)
	{
		f[cur] = calc(i-1,nearest[i][1]-1);
	}else
	{
		int k = nearest[i][0];
		int d1 = abs(a[i]-b[k]);
		int d2 = abs(a[i-1]-b[k]);
		if(nearest[i-1][0]!=k && nearest[i-1][1]!=k || d1<d2 || d2<d1 && k==nearest[i-1][1])
		{
			f[cur] = calc(i-1,k-1);
		}else
		if(d1==d2 && (k==nearest[i-1][0] || k==nearest[i-1][1]))
		{
			f[cur] = calc(i-2,k-1);
		}else
		{
			f[cur] = calc(i-1,j) + 1;
		}
	}
	return f[cur];
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
	printf("%d\n",calc(n-1,m-1));
	return 0;
}
