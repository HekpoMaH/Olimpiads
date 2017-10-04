#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long> d[100];
void calc(int x,int y,int mask,int next_mask)
{
    if(x==n)
    return;
    if(y>=m)d[x+1][next_mask]+=d[x][mask];
    else
    {
        int mymask=(1<<y);
        if(mask&mymask)calc(x,y+1,mask,next_mask);
        else
        {
            calc(x,y+1,mask,next_mask|mymask);
            if(y+1<m&&!(mask&mymask)&&!(mask&(mymask<<1)))calc(x,y+2,mask,next_mask);
        }
    }
}
int main()
{
    cin>>n>>m;

    for(int i=0;i<=n;i++)
    {   d[i].resize(1<<m);
        //for(int j=0;j<d[i].size();j++)cout<<d[i][j]<<" ";cout<<endl;
    }
    d[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int mask=0;mask<(1<<m);mask++)
        {
            calc(i,0,mask,0);
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<d[i].size();j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<d[n][0]<<endl;
}
