/*
	Розв'язання через паросполучення
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

const int maxn=100010;
const int inf=1000000000;

struct edge{
	int v;
	int cap;
	edge* rev;
	edge() {}
	edge(int v,int cap):v(v),cap(cap) {}
};

int n,m,k,y0,y1,i,j,s,t;
int a[maxn],b[maxn];
int nearest[maxn][2],c[maxn];
int cnearest[maxn][2],cc[maxn],cd[maxn][2];
edge e[8*maxn];
int ecnt;
vector<edge*> g[2*maxn+2];
bool used[2*maxn+2];
int st[2*maxn+2],stk;
pii cur[2*maxn+2];

void setMice(int i,int j)
{
	int k = a[i]<=b[j] ? 0: 1;
	int curd = abs(b[j]-a[i]);
	if(curd<cd[j][k])
	{
		cd[j][k] = curd;
		cnearest[j][k]=i;
	}
}

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
	for(i=0;i<m;i++)
		for(j=0;j<2;j++)
		{
			cd[i][j] = inf;
			cnearest[i][j] = -1;
		}
	for(i=0;i<n;i++)
		for(j=0;j<c[i];j++)
			setMice(i,nearest[i][j]);
	for(i=0;i<m;i++)
		cc[i] = (cd[i][0]==cd[i][1])? 2: 1;
}

edge* addEdge(int v,int cap)
{
	e[ecnt] = edge(v,cap);
	return &e[ecnt++];
}

void addEdges(int v,int w,int cap)
{
	edge *e1 = addEdge(w,cap);
	edge *e2 = addEdge(v,0); 
	e1->rev = e2;
	e2->rev = e1;
	g[v].push_back(e1);
	g[w].push_back(e2);
}

bool dfs(int v)
{
	if(v == t)return true;
	used[v] = 1;
	st[stk++] = v;
	for(int i=0;i<g[v].size();i++)
		if(g[v][i]->cap && !used[g[v][i]->v] && dfs(g[v][i]->v))
		{
			g[v][i]->cap--;
			g[v][i]->rev->cap++;
			return true;
		}
	return false;
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
	s = 0;
	t = n+m+1;
	for(i=1;i<=n;i++)
		addEdges(s,i,1);
	for(i=0;i<m;i++)
		for(j=0;j<2;j++)
			if(cnearest[i][j] != -1)
				addEdges(cnearest[i][j]+1,i+n+1,1);
	for(i=1;i<=m;i++)
		addEdges(i+n,t,cc[i-1]);
	int ans=n;
	while(dfs(s))
	{
		ans--;
		for(i=0;i<stk;i++)
			used[st[i]]=false;
		stk=0;
	}
	printf("%d\n",ans);
	return 0;
}
