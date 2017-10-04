#include<bits/stdc++.h>
using namespace std;
int n;
unsigned int ans[1<<21+1];
int lev,a[29][3];;
unsigned int go(int mask, int level,int lp)
{
    unsigned int cur=0,best=0;
    if(level>=lev)return 0;
    if(ans[mask]!=-1)return ans[mask];

    for(int i=0;i<n-1;i++)if((mask&(1<<i))==0)
    {
        for(int j=i+1;j<n;j++)if((mask&(1<<j))==0)
        {//cout<<"E"<<endl;
            if(j==n&&lp==1)continue;
            if(j<n-1)cur=go(mask|1<<i|1<<j,level+1,lp);
            else cur=go(mask|1<<i,level+1,1);
            cur+=(a[i][1]-a[j][1])*(a[i][1]-a[j][1]);
            cur+=(a[i][2]-a[j][2])*(a[i][2]-a[j][2]);
            //cout<<cur<<endl;
            best=max(best,cur);
        }
    }
    ans[mask]=best;
    return best;
}
int main()
{
    unsigned o;
    ios_base::sync_with_stdio(false);
    memset(ans,-1,sizeof(ans));
    cin>>n;lev=n/2;
    for(int i=0;i<n;i++)cin>>a[i][1]>>a[i][2];
    o=go(0,0,0);
    cout<<o<<".000\n";
}
