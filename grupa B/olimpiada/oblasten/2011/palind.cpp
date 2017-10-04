#include<bits/stdc++.h>
using namespace std;
int dp[20009][3];
int p[20009][3];
int t[20009];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,br=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<=n;i++)
    {
        int j=1;
        while(i-j>=1&&i+j<=n)
        {
            if(t[i-j]!=t[i+j])break;
            j++;
        }
        j--;
        br++;
        p[br][1]=i-j;
        p[br][2]=i+j;
    }
    for(int i=1;i<n;i++)
    {
        int j=1;
        while(i-j+1>=1&&i+j<=n)
        {
            if(t[i-j+1]!=t[i+j])break;
            j++;
        }
        j--;
        br++;
        if(j!=0)p[br][1]=i-j+1,p[br][2]=i+j;
    }
    dp[1][1]=dp[1][2]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][1]=i;dp[i][2]=i;
        for(int j=1;j<=br;j++)
        {
            int x=p[j][2]-i,y=p[j][1]+x;
            if(x>=0&&y<=i&&dp[i][2]>dp[y-1][2]+1)dp[i][2]=dp[y-1][2]+1,dp[i][1]=y;
        }
    }
    cout<<dp[n][2]<<"\n";
    if(dp[n][2]!=1)
    {
        vector<int> ans;
        int curr=dp[n][2],idx=n;
        while(curr>1)
        {
            curr--;
            ans.push_back(dp[idx][1]-1);
            //cout<<dp[idx][1]-1<<endl;
            idx=dp[idx][1]-1;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<dp[n][2]-1;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}
