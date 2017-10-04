#include<iostream>
#include<cstring>
#include<algorithm>
#define mp make_pair
using namespace std;
const int M=2000;
int n,m,table[M][M],dp[M][M];
int dpleft[M],dpright[M],row[M];
pair<int,int> st[M];
void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>table[i][j];
            if(!table[i][j])
            {
                table[i][j]=table[i-1][j]+1;

            }else table[i][j]=0;
        }
    }

}
void solve()
{
    int sz,sum=0,i,j;
    for(i=1;i<=n;i++)
    {
        memset(dpleft,0,sizeof(dpleft));
        memset(dpright,0,sizeof(dpright));
        sz=-1;
        for(j=1;j<=m;j++)
        {
            sum=0;
            while(sz>=0)
            {
                if(st[sz].first>=table[i][j])
                {
                    sum+=st[sz].second;sz--;
                }
                else break;
            }
            st[++sz]=mp(table[i][j],sum+1);
            dpleft[j]=sum+1;
        }
        sz=-1;
        for(j=m;j>=1;j--)
        {
            sum=0;
            while(sz>=0)
            {
                if(st[sz].first>=table[i][j])
                {
                    sum+=st[sz].second;sz--;
                }
                else break;
            }
            st[++sz]=mp(table[i][j],sum+1);
            dpright[j]=sum+1;
        }
        memset(row,0,sizeof(row));
        for(j=1;j<=m;j++)row[table[i][j]]=max(row[table[i][j]],dpright[j]+dpleft[j]-1);
        int len=0;
        for(j=1;j<=i;j++)len=max(len,row[i-j+1]),dp[i][j]=(i-j+1)*len;
        for(j=i;j>=1;j--)dp[i][j]=max(dp[i][j],dp[i-1][j]),dp[i][j]=max(dp[i][j],dp[i][j+1]);//,cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
    }
    //cout<<dp[1][2]<<endl;
}
int main()
{
    input();
    solve();
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,x,y,i;
    cin>>t;
    for(i=1;i<=t;i++)cin>>x>>y,cout<<dp[y][x]<<"\n";
}
