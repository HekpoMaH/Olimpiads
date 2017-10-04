#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#define ll long long

using namespace std;
  
const int MAX = 1000000;
const ll MOD = 9007199254740991LL;

    char s[MAX + 5];

    int n;
    int pos[1<<6];
    ll dp[MAX + 5];

int main()
{
    scanf("%s", s);
    n = (int)strlen(s);

    memset(pos, -1, sizeof(pos));

    for( int i = n - 1; i >= 0; --i )
    {
     dp[i] = 1;

     for( int j = 0; j < 26; ++j )
      if( pos[j] != -1 ) { dp[i] += dp[pos[j]]; dp[i] %= MOD; }

     pos[ s[i] - 'a' ] = i;
    //  cout<<i<<" "<<dp[i]<<"\n";
    } 

    ll ans = 0;
    for(int i = 0; i < 26; ++i) 
     if(pos[i] != -1) { ans += dp[pos[i]]; ans %= MOD; }

    printf("%lld\n",ans);
return 0;
}
