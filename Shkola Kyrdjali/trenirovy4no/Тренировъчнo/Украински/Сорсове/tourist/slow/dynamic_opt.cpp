/*
	O(n^2) dynamic solution with optimization
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define X first
#define Y second
#define N 100010

int n,v,i,j;
pii a[N],f[N];

int calc(int hasTransport)
{
	f[0].X=0;	
	f[0].Y=0;
	int i,j;
	for(i=1; i<=n; i++)
	{
		f[i].Y = i;
		for(j=i-1;j>=0 && abs(a[i].Y-a[f[j].Y].Y)>ll(v)*(a[i].X-a[f[j].Y].X);j--);
		if(j>=0)
			f[i].X = f[j].X + 1;else
			f[i].X = hasTransport;
		for(j=i;j>0 && f[j].X<f[j-1].X;j--)
			swap(f[j],f[j-1]);
	}
	return f[n].X;
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
