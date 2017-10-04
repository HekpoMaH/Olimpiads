/*
	Bruteforce
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define X first
#define Y second
#define N 100010

int n,v,i,j,ans;
pii a[N];

int Search(int d,int cur)
{
	if(cur+n-d+1>ans) {
		ans = max(ans,cur);
		int res = cur;
		for(int i=d+1;i<=n;i++)
			if(abs(a[i].Y-a[d].Y)<=ll(v)*(a[i].X-a[d].X))
				res = max(res,Search(i,cur+1));
		return res;
	}
	return 0;
}

int calc(int hasTransport)
{
	if(!hasTransport) {
		ans = 0;
		return Search(0,0);
	}else {
		int res = 0;
		for(int i=1;i<=n;i++)
		{
			ans = 0;
			res = max(res,Search(i,1));
		}
		return res;
	}
}

int main()
{
	
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
