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
#define problem "mutation"

int a,b,c,d,i,j,n,m,k,T,ans,q;
int p[22],cs[22][22];
char str[200002];
int main()
{
	freopen(problem ".dat","r",stdin);
	freopen(problem ".sol","w",stdout);
	scanf("%d%d%d\n",&n,&k,&T);
	gets(str);
	rept(i,n) str[i]-='A',q|=1<<str[i];
	rept(i,k) scanf("%d",&p[i]);
	rept(i,k) rept(j,k) scanf("%d",&cs[i][j]);

	rept(mask,q)
	{
		if ((q&mask)!=mask) continue;
		c=0;
		rept(j,k) if (mask&1<<j) c+=p[j];
		if (c>T) continue;
		a=-1;
		rept(i,n)
		{
			if (mask&1<<(str[i])) continue;
			if (a!=-1) c+=cs[a][str[i]];
			a=str[i];
			if (c>T) break;
		}
		if (c<=T) ++ans;
	}
	printf("%d\n",ans);
}
