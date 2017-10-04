 #include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int n, m;
struct node {int x,y;};
vector <int> g[1000];
int visit[1000], path[1000];
int nivo, in, ir;

node nodes[40000], rnodes[2000];

int cmp(node a,node b){
    if(a.x<b.x) return 1;
    if(a.x>b.x) return 0;
    return a.y<b.y;
    }

int eq (node a, node b) {
    if (a.x==b.x && a.y==b.y) return 1;
    else return 0;
}

void allpaths(int i, int j)
 {
       int k, v;
  if (i!=j){
	visit[i]=1;
	path[nivo++]=i;
	for (k=0;k<g[i].size();k++){
	 v=g[i][k];
     if (!visit[v]) allpaths(v,j);
    }
	 visit[i]=0;
	 nivo--;
	 return;
  }
	path[nivo]=i;
	for (k=0;k<=nivo;k++){
        node u;
        u.x=path[k]; u.y=k;
        nodes[in++]=u;
    }
 }
int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;i++)
    {
        int a, b, w; scanf("%d %d", &a, &b);
        g[a].push_back(b); g[b].push_back(a);
    }
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int i=0;i<n;i++)visit[i]=0;
    nivo=0; in=0;
    allpaths(x1, y1);
    sort (nodes, nodes+in, cmp);
    int k=1, ir=0; rnodes[0]=nodes[0];
    while (k<in){
          if (!eq(rnodes[ir],nodes[k]))
                rnodes[++ir]=nodes[k];
          k++;
    }
    for (int i=0;i<n;i++)visit[i]=0;
    nivo=0; in=0;
    allpaths(x2, y2);
    sort (nodes, nodes+in, cmp);
    k=1; rnodes[++ir]=nodes[0];
    while (k<in){
          if (!eq(rnodes[ir],nodes[k]))
                rnodes[++ir]=nodes[k];
          k++;
    }
    sort(rnodes, rnodes+ir, cmp);
    in=0; int br=0;
    while (in<ir){
          if (eq(rnodes[in],rnodes[in+1])){
                 path[br]=rnodes[in].x;
                 br++; in+=2;
          }
          else in++;
    }
    in=0; int brn=0;
    while (in<br){
          ir=in+1; brn++;
          while (path[in]==path[ir]) ir++;
          in=ir;
    }
    printf("%d\n", brn);
    return 1;
}