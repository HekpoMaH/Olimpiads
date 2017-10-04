#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a,b,c,d,i,j,n,m,k,ans,T;
char str[200003];
int p[22],cs[22][22],dp[1<<21];
pii cur[26];

int main()
{
	freopen("mutation.dat","r",stdin);
	freopen("mutation.sol","w",stdout);
	scanf("%d%d%d",&n,&k,&T);
	scanf("%s",str);
	rept(i,k) scanf("%d",&p[i]);
	rept(i,k) rept(j,k) scanf("%d",&cs[i][j]);

	cur[0]=mp(-1,-1);
	int were=0;
	
	FORD(i,n-1,0)
	{
		int mask=0,t=str[i]-'A';
		were|=1<<t;
		rept(j,k)
		{
			if (cur[j].x==-1) break;
			dp[mask]+=cs[t][cur[j].y];
			dp[mask|1<<t]-=cs[t][cur[j].y];
			dp[mask|1<<cur[j].y]-=cs[t][cur[j].y];
			dp[mask|(1<<t)|(1<<cur[j].y)]+=cs[t][cur[j].y];
			mask|=1<<cur[j].y;
			if (cur[j].y==t) break;
		}
		rept(j,k)
		{
			if (cur[j].x==-1 || cur[j].y==t)
			{
				bool tt=0;
				if (cur[j].x==-1) tt=1;
				cur[j]=mp(i,t);
				FORD(z,j-1,0) swap(cur[z],cur[z+1]);
				if (tt) cur[j+1]=mp(-1,-1);
				break;
			}
		}
	}

	ans=0;

	rept(mask,were)
	{
		if ((mask&were)!=mask) continue;
		int c=0;
		rept(i,k) if (mask&1<<i) c+=p[i];
		for (int nmask=mask;;nmask=(nmask-1)&mask)
		{
			c+=dp[nmask];
			if (!nmask) break;
		}
		if (c<=T) ++ans;
	}
	printf("%d\n",ans);

	//cerr<<clock()<<endl;
}
