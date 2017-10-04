/*
	O(n^2) dynamic solution
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define X first
#define Y second
#define N 100010

int n,v,i,j;
int f[N];
pii a[N];

int calc(int hasTransport)
{
	f[0]=0;	
	for(i=1; i<=n; i++)
	{
		f[i] = hasTransport;
		for(j=i-1; j>=0; j--)
			if(abs(a[i].Y-a[j].Y)<=ll(v)*(a[i].X-a[j].X) && f[i]<f[j]+1)
				f[i] = f[j]+1;
	}
	int ans=0;
	for(i=1;i<=n;i++)
		ans = max(ans,f[i]);
	return ans;
}

int main()
{
	freopen("tourist.dat","r",stdin);
	freopen("tourist.sol","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].Y,&a[i].X);
	scanf("%d",&v);
	a[0].Y=a[0].X=0;
	sort(a,a+n+1);
	int ans1 = calc(1);
	for(i=1;i<=n;) {
		if(abs(a[i].Y)>ll(v)*a[i].X) {
			swap(a[i],a[n]);
			n--;
		}else{
			i++;
		}
	}
	sort(a,a+n+1);
	int ans0 = calc(0);
	printf("%d %d\n",ans0,ans1);
	return 0;
}
