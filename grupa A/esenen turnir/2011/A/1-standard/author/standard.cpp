#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

#define mp make_pair

using namespace std;

const int M = 2000;

    int n, m;
    int table[M][M];
    int dp[M][M]; //dp[i][j] - the maximum rectangle that we can fit between rows (j, j+1, ..., i) 1<=j<=i<=n
    
    int dpLeft[M];
    int dpRight[M];
    
    int row[M];
    
    pair<int,int> st[M];
    
void input(){
 
    scanf("%d%d", &n, &m);
    for( int i = 1; i <= n; ++i )
      for( int j = 1; j <= m; ++j ){
      
	scanf("%d", &table[i][j]);
	if( !table[i][j] ) table[i][j] = table[i-1][j] + 1;
	else table[i][j] = 0;
	
	//printf("%d ", table[i][j]); if( j == m ) printf("\n");
      }
}

void solve(){

    int sz, sum = 0;
    
    for( int i = 1; i <= n; ++i ){
      
      memset( dpLeft, 0, sizeof(dpLeft) );
      memset( dpRight, 0, sizeof(dpRight) );
      
      sz = -1;
      for( int j = 1; j <= m; ++j ){
	
	sum = 0;
	while( sz >= 0 ){
	  if( st[sz].first >= table[i][j] ) {sum += st[sz].second; sz--;}
	  else break;
	}
	
	st[++sz] = mp(table[i][j], sum + 1);
	dpLeft[j] = sum + 1;
	
      }
      
      sz = -1;
      for( int j = m; j >= 1; --j ){
	
	sum = 0;
	while( sz >= 0 ){
	  if( st[sz].first >= table[i][j] ) {sum += st[sz].second; sz--;}
	  else break;
	}
	
	st[++sz] = mp(table[i][j], sum + 1);
	dpRight[j] = sum + 1;
	
      }

      memset( row, 0, sizeof(row) );
      
      for( int j = 1; j <= m; ++j ) row[ table[i][j] ] = max( row[ table[i][j] ], dpRight[j] + dpLeft[j] - 1 );

      int len = 0;
      for( int j = 1; j <= i; ++j ){
	 len = max(len, row[i-j+1]);
	 dp[i][j] = (i-j+1) * len;
      }
      
      for( int j = i; j >= 1; --j ){
	dp[i][j] = max( dp[i][j], dp[i-1][j] );
	dp[i][j] = max( dp[i][j], dp[i][j+1] );
      }
    }
}
int main()
{
    input();
    solve();
    
    int t;
    scanf("%d", &t);
    for( ; t; t-- ){
    
      int u, v;
      scanf("%d%d", &u, &v);
      printf("%d\n",dp[v][u]);
    }
return 0;
}
