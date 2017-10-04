#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>

using namespace std;

     const int mod = 1800000007;

     int used[10];
     int C[200][200];
     int dp[200][20], mn;

inline int fix2(int x, int y)
{
   unsigned long long cc = x; cc *= y;
   cc %= mod;
return (int)cc;
}

inline int fix(int x, int y)
{
   long long cc = x; cc += y;
   cc %= mod;
return (int)cc;
}

int go(int need,int pos)
{
    if( need != 0 && pos == 10 ) return 0;
    if( dp[need][pos] != -1 ) return dp[need][pos];
    if( need == 0 ) return 1;

    dp[need][pos] = 0;

    for( int i = 1; i <= need && i <= used[pos]; ++i )
    {
     if( pos == 0 && i < need ) dp[need][pos] = fix( dp[need][pos], fix2(C[need-1][i], go(need - i, pos + 1)) );
     else
     if( pos != 0 ) dp[need][pos] = fix( dp[need][pos], fix2(C[need][i], go(need - i, pos + 1)) );
    }

    dp[need][pos] = fix( dp[need][pos], go(need, pos + 1));
return dp[need][pos];
}

int main()
{

    memset(dp, -1, sizeof(dp));

    while( 1 )
    {
     char ch = getchar();
     if( feof(stdin) ) break;
     if( ch == '\n' ) break;
     if( !(ch >= '0' && ch <= '9') ) break;
     used[(int)ch - '0'] ++;
     mn ++;
    }
    cout<<mn<<endl;
    C[0][0] = 1;

    for( int i = 1; i <= 120; ++i ){

     C[i][0] = 1;

     for( int j = 1; j <= i; ++j )
      C[i][j] = fix(C[i-1][j], C[i-1][j-1]);

     }

    int ans = 0;

    for( int i = 1; i <= mn; ++i )
     ans = fix( ans, go(i,0) );

    if(used[0])ans++;

    ans %= mod;
    printf("%d\n",ans);

return 0;
}
