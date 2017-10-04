#include<iostream>
#include<set>
using namespace std;
int n,a[52],b,m,ans;
set<int>dp[52];
set<int>::iterator it;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>b>>m;
    dp[0].insert(b);
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<"-> ";
        for(it=dp[i-1].begin();it!=dp[i-1].end();it++)
        {
            if(*it-a[i]>=0)dp[i].insert(*it-a[i]);
            if(*it+a[i]<=m)dp[i].insert(*it+a[i]);
        }
        
        if(dp[i].size()==0){cout<<-1<<endl;return 0;}
    }
    for(it=dp[n].begin();it!=dp[n].end();it++)
    {
        ans=*it;
    }
    cout<<ans<<endl;
    return 0;
}