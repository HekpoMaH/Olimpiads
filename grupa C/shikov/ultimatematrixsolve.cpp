#include<iostream>
#include<string>
using namespace std;
struct mb
{
    long long cena,redove,koloni;int tcepene;
};
struct mout
{
    string left;
    string right;
};
mout ans[1000];
int rs[1000];
mb dp[1005][1005];
int n,tc,used[1000][1000];
void print(int lqv,int desen)
{
    if(lqv<desen){ans[lqv].left="("+ans[lqv].left;
    ans[desen].right+=")";}
    //cout<<"lqv="<<lqv<<" desen="<<desen<<" tcepene="<<dp[lqv][desen].tcepene<<endl;
    if(dp[lqv][desen].tcepene>0&&used[lqv][dp[lqv][desen].tcepene]==0)
    {
        print(lqv,dp[lqv][desen].tcepene);
    }
    if(dp[lqv][desen].tcepene>0&&used[dp[lqv][desen].tcepene+1][desen]==0)
    {
        print(dp[lqv][desen].tcepene+1,desen);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)cin>>rs[i];
    for(int i=1;i<=n;i++)
    {
        dp[i][i].cena=0;dp[i][i].redove=rs[i-1];dp[i][i].koloni=rs[i];
        //cout<<dp[i][i+1]<<endl;
    }
    int mn;
    for(int k=1;k<n;k++)
    {
        for(int i=1;i<=n-k;i++)
        {
            dp[i][i+k].redove=rs[i-1];dp[i][i+k].koloni=rs[i+k];
            mn=99999999;
            for(int f=i;f<=i+k-1;f++)
            {
                if(dp[i][f].cena+dp[f+1][i+k].cena+dp[i][f].redove*dp[i][f].koloni*dp[f+1][i+k].koloni<mn)
                {
                    mn=dp[i][f].cena+dp[f+1][i+k].cena+dp[i][f].redove*dp[i][f].koloni*dp[f+1][i+k].koloni;
                    tc=f;
                }
                //mn=min(mn,dp[i][f].cena+dp[f+1][i+k].cena+dp[i][f].redove*dp[i][f].koloni*dp[f+1][i+k].koloni);
            }
            dp[i][i+k].tcepene=tc;
            dp[i][i+k].cena=mn;
        }
    }
    cout<<dp[1][n].tcepene<<endl;
    //return 0;
    print(1,n);
    //cout<<"(";
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i].left<<"m"<<i<<ans[i].right;
    }
    cout<<endl;
    cout<<dp[1][n].cena<<endl;
    return 0;
}