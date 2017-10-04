#include <iostream>
#define MAXN 600
#define MOD 1000000021
#define INF 1000000000
using namespace std;
int G[MAXN][MAXN],N,M,Q;
long long P[MAXN][MAXN];
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
int i,j,k,u,v,c;
cin>> N >> M;
for(i=1;i<=N;i++)
{ for(j=1;j<=N;j++) {G[i][j]=INF;P[i][j]=0;}  G[i][i]=0;
}
for(i=1;i<=M;i++)
{ cin >> u >> v >> c;
G[u][v]=G[v][u]=c;
P[u][v]=P[v][u]=1;
}
for(k=1;k<=N;k++)
for(i=1;i<=N;i++)
for(j=1;j<=N;j++)
if(G[i][k]+G[k][j]<G[i][j])
{ G[i][j]=G[i][k]+G[k][j];
P[i][j]=(P[i][k]*P[k][j])%MOD;
}
else if(G[i][k]+G[k][j]==G[i][j])
P[i][j]=(P[i][j]+P[i][k]*P[k][j])%MOD
;
cin >> Q;
for(i=1;i<=Q;i++)
{ cin >> u >> v;
if(u==v) cout << 1;
else cout << P[u][v];
if(i<Q) cout << " "; else cout << "\n";
}
return 0;
} 
