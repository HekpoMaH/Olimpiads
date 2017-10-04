#include<bits/stdc++.h>
using namespace std;
string mans;
int ans[1009];
int go6o[44],joro[44];
int n,m,s;
clock_t ti;
void solve()
{
    memset(ans,0,sizeof(ans));
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);*/
    int l;
    cin>>s>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>go6o[i];
    }
    for(int i=1;i<=m;i++)cin>>joro[i];
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-go6o[j]==0){ans[i]=1;break;}
            l=1;
            if(i-go6o[j]>0)for(int k=1;k<=m;k++)
            {
                //if((double)(((double)(ti-clock())/(double)CLOCKS_PER_SEC))>0.05)cout<<"EEE"<<endl,exit(0);
                if((i-go6o[j]-joro[k]>=0&&ans[i-go6o[j]]==0&&ans[i-go6o[j]-joro[k]]==0)||i-go6o[j]-joro[k]<0)l=0;
            }
            if(l==1&&i-go6o[j]>0){ans[i]=1;break;}
        }
    }
    /*for(int i=1;i<=s;i++)cout<<ans[i]<<" ";
    cout<<endl;*/
    if(ans[s]==1)mans+='y';
    else mans+='n';
}
int main()
{
    //ti=clock();
    int t;
    cin>>t;
    while(t--)solve();
    //ti=clock()-ti;
    //if((double)(((double)(ti-clock())/(double)CLOCKS_PER_SEC))>0.05)cout<<"EEE"<<endl;
    //cout<<(double)(((double)ti/(double)CLOCKS_PER_SEC))<<endl;
    cout<<mans<<endl;
}
