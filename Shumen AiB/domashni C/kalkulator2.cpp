#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int n,hod[1000005];
long long dp[1000005];
stack<int> s;
int main()
{
    cin>>n;
    memset(dp,31,sizeof(dp));
    dp[1]=0;
    for(int i=1;i<n;i++)
    {
        if(dp[i+1]>dp[i]+1)
        {
            dp[i+1]=dp[i]+1;
            hod[i+1]=1;
        }
        if(i*2<=n&&dp[i*2]>dp[i]+1)
        {
            dp[i*2]=dp[i]+1;
            hod[i*2]=2;
        }
        if(i*3<=n&&dp[i*3]>dp[i]+1)
        {
            dp[i*3]=dp[i]+1;
            hod[i*3]=3;
        }
    }
    while(n!=1)
    {
        s.push(hod[n]);
        if(hod[n]==1)n-=1;
        else if(hod[n]==2)n/=2;
        else if(hod[n]==3)n/=3;
    }
    if(s.size()==0)return 0;
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    //cout<<dp[n]<<endl;
    return 0;
}