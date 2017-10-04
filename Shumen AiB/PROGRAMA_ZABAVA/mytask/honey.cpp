#include<iostream>
#include<vector>
using namespace std;
int n,k,m;
vector<int> p[102];
int dl[103][10004];
int dp[104][10004];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x;
            cin>>x;
            p[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int sz=p[i].size();
        int sum[sz+22];
        sum[0]=p[i][0];
        for(int j=1;j<sz;j++)sum[j]=sum[j-1]+p[i][j];

        for(int l=-1;l<sz;l++)
        {
            for(int r=sz;r>l;r--)
            {
                long long curr=0;
                if(r!=sz)curr+=sum[sz-1]-(r==0 ? 0 : sum[r-1]);
                if(l>=0)curr+=sum[l];
                if(curr>dl[i][l+1+sz-r])dl[i][l+1+sz-r]=curr;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=0;
            //cout<<"p["<<i<<"].size()="<<p[i].size()<<endl;
            for(int k=0;k<=min((int)p[i].size(),j);k++)
            dp[i][j]=max(dp[i][j],dp[i-1][j-k]+dl[i][k]);
        }
    }
    cout<<dp[n][m]<<endl;
}
