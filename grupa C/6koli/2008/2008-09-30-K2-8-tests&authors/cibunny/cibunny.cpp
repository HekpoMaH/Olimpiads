#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int inf = 1<<30;

#define mp make_pair

int n , m;
int cost[128];
int dp[128];
int used[128];
vector < int > a[128];

void read() {
    scanf ("%d",&n);
    int x , y;
    int i;
    
    for (i=1;i<=n;i++) scanf ("%d",&cost[i]);
    
    scanf ("%d",&m);
    
    while ( m ) {
        scanf ("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
                
        --m;
    }
}

struct Cmp {
    int operator () ( pair<int,int> a , pair<int,int> b ) {
        return a.second > b.second;
    }
};

int dijkstra ( int s , int e ) {
    int i;
    int sz;
    pair<int,int> cur;
    priority_queue < pair<int,int> , vector < pair<int,int> > , Cmp > pq;
    
    for (i=1;i<=n;i++) {
        dp[i] = inf;
        used[i] = 0;
    }
    
    dp[s] = 0;
    pq.push( mp(s,0) );
    
    while ( !pq.empty() ) {
        cur = pq.top();
        pq.pop();
        if ( used[cur.first] ) continue;
        
        if ( cur.first == e ) return dp[cur.first];
        
        sz = a[cur.first].size();
        
        for (i=0;i<sz;i++) {
            if ( dp[ a[cur.first][i] ] > cur.second + cost[cur.first] ) {
                pq.push ( mp ( a[cur.first][i] , cur.second + cost[cur.first] ) );
                dp[ a[cur.first][i] ] = cur.second + cost[cur.first];
            }
        }
    }
    
    return -1;
}

void solve() {
    printf ("%d\n",dijkstra(1,n));
}

int main() {
    read();
    solve();
    
    return 0;
}
