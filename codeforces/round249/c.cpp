#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int offset=2000;
int a[1009],n;
set<pair<int,int> >pnts;
int ans[offset*2][offset*2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x=offset,y=offset,mx,mn,sum=0,prevx,prevy;
    mx=mn=offset;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];sum+=a[i];
        if(i%2==1)
        {
            prevx=x-1;prevy=y;
            for(int j=1;j<=a[i];j++)ans[prevx+j][prevy+j]=1;
            x+=a[i];y+=a[i];
            mx=max(mx,x);
        }
        else
        {
            prevx=x;prevy=y;
            for(int j=1;j<=a[i];j++)ans[prevx-j][prevy+j]=2;
            x-=a[i];y+=a[i];
            mn=min(mn,x);
        }
    }
    for(int i=mx-1;i>=mn;i--)
    {
        for(int j=2001;j<=sum+2000;j++)
        {
            if(ans[i][j]==1)cout<<"/";
            else if(ans[i][j]==2)cout<<"\\";
            else cout<<" ";
        }cout<<"\n";
    }

}
