#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
#define mp make_pair

using namespace std;

struct el
{
   int x, prev;
   int cost;
 
   el(){}
   el( int _x, int _prev, int _cost ) { x = _x; prev = _prev; cost = _cost; }

   bool operator < (const el &p) const{

     return cost > p.cost;
}

};

    const int MAX = 200000;

    priority_queue<el> pq;

    vector< pii > all;
    vector<int> G[MAX], Gc[MAX];

    int cost[MAX], dist[MAX], n;
    bool used[MAX];

bool cmp( pii p1, pii p2 )
{
    if(p1.first == p2.first ) return p1.second < p2.second;
return p1.first < p2.first;
}
void input()
{
    int m;
    scanf( "%d%d", &n, &m );

    for( int i = 1; i <= n; ++i ) scanf("%d", &cost[i] );
    for( int i = 1; i <= n; ++i ) dist[i] = 2000000000;
 
    for( ; m; m-- )
    {
      int x, y, c;
      scanf("%d%d%d", &x, &y, &c);
  
      if( x > y ) swap( x, y );

      G[x].push_back(y); Gc[x].push_back( (c/2 + c%2) * cost[x] + (c/2) * cost[y] );
      G[y].push_back(x); Gc[y].push_back( (c/2) * cost[y] + (c/2 + c%2) * cost[x] );
    }
}

void prim()
{
     while( (int)pq.size() > 0 ) pq.pop();

     dist[1] = 0; used[1] = 1;
     pq.push( el( 1, 0, 0 ) );

     long long ans = 0;

     while( (int)pq.size() > 0 ){

	el tmp = pq.top();
        pq.pop();

	if( dist[tmp.x] < tmp.cost ) continue;

        //printf( "out %d %d %d\n", tmp.x, tmp.prev, tmp.cost );
        int x = tmp.x;
        used[x] = 1;

        if( tmp.prev != 0 ) all.push_back( mp( min(x,tmp.prev), max(x,tmp.prev) ) );
        ans += tmp.cost;

        for( int i = 0; i < (int)G[x].size(); ++i )
        if( !used[ G[x][i] ] && dist[ G[x][i] ] > Gc[x][i] )
	{
	  dist[ G[x][i] ] = Gc[x][i];
	  pq.push( el(G[x][i], x, Gc[x][i]) );
	}
     }
     printf("%lld\n",ans);

     sort( all.begin(), all.end(), cmp );

     for( int i = 0; i < (int)all.size(); ++i )
      printf("%d %d\n",all[i].first, all[i].second);
}
int main()
{
    input();
    prim();
return 0;
}
