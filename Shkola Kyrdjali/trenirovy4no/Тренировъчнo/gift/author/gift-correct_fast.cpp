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
#define INFLL 2000000000000000000LL

int a,b,c,d,i,j,n,m,k,g,s;
ll ans;
pair<pii,pii> edges[50001];
VI sm[201];

int cs[201][201];
pii cur[201];

bool found;

bool used[201];

inline void removeSm(int oa,int ob)
{
	rept(i,L(sm[oa]))
	{
		if (sm[oa][i]==ob)
		{
			swap(sm[oa][i],sm[oa].back());
			sm[oa].ppb();
			return;
		}
	}
}
inline void replaceTreeEdge(int oa,int ob,int a,int b,int c)
{
	removeSm(oa,ob);
	removeSm(ob,oa);

	sm[a].pb(b); sm[b].pb(a);
	cs[a][b]=cs[b][a]=c;
	cs[oa][ob]=cs[ob][oa]=cs[0][0];
	rept(i,k)
	{
		if ((cur[i].x==oa && cur[i].y==ob) || (cur[i].x==ob && cur[i].y==oa))
		{
			cur[i]=mp(a,b);
			break;
		}
	}
}


void dfs(int v,int st,int en,int c,int cur=-1,int ca=-1,int cb=-1)
{
	used[v]=1;
	if (v==en)
	{
		found=1;
		if (cur<=c) return;

		replaceTreeEdge(ca,cb,st,en,c);

		return;
	}
	
	rept(i,L(sm[v]))
	{
		int w=sm[v][i];
		if (used[w]) continue;
		int nx=cur,na=ca,nb=cb;
		if (cs[v][w]>nx)
		{
			nx=cs[v][w];
			na=v; nb=w;
		}

		dfs(w,st,en,c,nx,na,nb);
		if (found) return;
	}
}
inline void addEdge(int a,int b,int c)
{
	if (a==b) return;
	if (cs[a][b]<=INF)
	{
		if (cs[a][b]<=c) return;
		cs[a][b]=cs[b][a]=c;
		return;
	}
	memset(used,0,n);
	found=0;
	dfs(a,a,b,c);

	if (!found)
	{
		cur[k++]=mp(a,b);
		cs[a][b]=cs[b][a]=c;
		sm[a].pb(b); sm[b].pb(a);
	}
}
int main()
{
	

	scanf("%d%d",&n,&m);
	scanf("%d%d",&g,&s);
	rept(i,m)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d); --a; --b;
		edges[i]=mp(mp(c,d),mp(a,b));
	}
	sort(edges,edges+m);

	memset(cs,63,sizeof(cs));
	k=0;
	ans=INFLL+1;

	rept(i,m)
	{
		addEdge(edges[i].y.x,edges[i].y.y,edges[i].x.y);
		if (k==n-1)
		{
			a=0;
			rept(j,n-1)	if (cs[cur[j].x][cur[j].y]>a) a=cs[cur[j].x][cur[j].y];

			if ((ll)a*s+(ll)g*edges[i].x.x<ans) ans=(ll)a*s+(ll)g*edges[i].x.x;
		}
	}

	if (ans>INFLL) ans=-1;
	cout<<ans<<endl;
}
