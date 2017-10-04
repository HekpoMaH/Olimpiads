#include<bits/stdc++.h>
using namespace std;
int a[100009];
int n;
int dp[100009],ans,it[100009][3],mx2,cbp;
//dp[i]- maximalnata redica s elementi po malki ili = ot a[i];
//it[i]- gotin na4in za namirane na max dp[j] , j<i;
int bp[100009];
int get(int ps)
{
    int mx=0;
    while(ps!=0)
    {
        if(it[ps][1]>mx)
        {
            //cbp=it[ps][2];
            mx=it[ps][1];
        }
        ps-=(ps&-ps);
    }
    return mx;
}
void update(int ps,int val)
{
    dp[ps]=val;
    while(ps<=n)
    {
        if(it[ps][1]<val)
        {
            it[ps][1]=val;
            //it[ps][2]=pm;
        }
        ps+=(ps&-ps);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        ans=get(a[i]-1);
        //namirame max dp[x], x<=a[i]-1 (strogo rastq6ta)
        //dp[a[i]]=dp[x]+1
        //update na darvoto
        update(a[i],ans+1);
        mx2=max(ans+1,mx2);
        //cout<<i<<endl;
    }
    cout<<mx2<<endl;
    //otgovora e max(dp[1],...,dp[maxa])
    
}