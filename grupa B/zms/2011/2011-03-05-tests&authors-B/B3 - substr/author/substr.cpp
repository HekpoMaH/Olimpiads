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
    ll dp[1<<6];

int main()
{
    scanf("%s", s);
    n = (int)strlen(s);

    ll tmp = 0;
    ll sum = 0;

    for( int i = n - 1; i >= 0; --i )
    {
     tmp = 1; tmp += sum; tmp %= MOD;

     sum -= dp[s[i]-'a']; sum += MOD; sum %= MOD;
     sum += tmp; sum %= MOD;

     dp[s[i] - 'a'] = tmp;
    } 
 
    cout<<sum<<"\n";

return 0;
}
