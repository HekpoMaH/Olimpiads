#include<bits/stdc++.h>
using namespace std;
int psr[1024][1024],psc[1024][1024],n;
int ans[1024][1024];
void readsolve()
{
    cin>>n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            psr[i][j]=psr[i][j-1]+x;
            psc[i][j]=psc[i-1][j]+x;
        }
    }
    //cout<<"N="<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(psr[i][j]%2==0&&ans[i-1][j]==0)ans[i][j]=1;
            else if(psc[i][j]%2==0&&ans[i][j-1]==0)ans[i][j]=1;
            else ans[i][j]=0;//cout<<i<<" "<<j<<" "<<psr[i][j]<<" "<<psc[i][j]<<endl;;
        }
    }
    //cout<<n<<endl;
    //cout<<ans[n][n]<<endl;
    if(ans[n][n]==1)cout<<"W"<<"\n";
    else cout<<"L"<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        //cout<<t<<endl;
        readsolve();memset(ans,0,sizeof(ans));memset(psr,0,sizeof(psr));memset(psc,0,sizeof(psc));
    }
}
