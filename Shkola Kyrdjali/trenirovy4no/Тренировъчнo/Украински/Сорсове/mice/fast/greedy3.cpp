#include <cstdio>
#include <algorithm>

const int maxn=100001;
const int maxm=100001;
const int inf=1000000000;

int n,m,y0,y1,i,j,d,lastd;
int a[maxn],b[maxn];
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
	ans=n;
	lastd=-1;
 	for(i=0,j=0;i<n;i++)
 	{
		while(j<m-1 && abs(b[j+1]-a[i])<abs(b[j]-a[i]))
		{
			j++;
			lastd = -1;
		}
	    d=abs(b[j]-a[i]);
		hasnext=(j<m-1 && abs(b[j+1]-a[i])==d);
		if(d<lastd && !hasnext)
			ans++;
		if(lastd==-1 || d==lastd || d<lastd && !hasnext)
		{
			ans--;
			lastd = d;
		}else
		if(hasnext)
		{
			j++;
			ans--;
			lastd = d;
		}
	}
	printf("%d\n",ans);
	return 0;
}
