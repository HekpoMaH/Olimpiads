#include<iostream>
using namespace std;

int s,n,dp[1<<20];

int main()
{
    cin>>s>>n;
    for(int i=1;i<=n;i++) dp[i]=1; //nakraq da go sloja s memset!! two parts
    for(int i=n+1;i<=s;i++)
    {
        dp[i] = dp[i-1] +1;
        for(int j=2;j<=n;j++)
        {
            dp[i] = min(dp[i], dp[i-j]+1);
            if(i%j==0) dp[i] = min(dp[i], dp[i/j]+1);
        }
    }
    cout<<dp[s]<<endl;
    return 0;
}
