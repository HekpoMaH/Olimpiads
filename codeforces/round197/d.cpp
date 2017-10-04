#include<bits/stdc++.h>
using namespace std;
int a[140000][20],n,m,pos,del=2,base;
void upd(int x,int y)
{
    a[x][1]=y;
    for(int i=1;i<=n;i++)
    {
        if(x%2==1)x++;
        if(i%2==1)
            {
                a[x/2][i+1]=a[x][i]|a[x-1][i];
            }
            if(i%2==0)
            {
                a[x/2][i+1]=a[x][i]^a[x-1][i];
            }
        x/=2;
    }
    cout<<a[1][n+1]<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=(1<<n);i++)
    {
        cin>>a[i][1];
    }
    base=(1<<n);
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=(1<<(n-i+1));j+=2)
        {
            if(i%2==1)
            {
                a[j/2][i+1]=a[j][i]|a[j-1][i];
                //cout<<i<<endl;
            }
            if(i%2==0)
            {
                a[j/2][i+1]=a[j][i]^a[j-1][i];
            }
        }
    }
    //cout<<a[1][n+1]<<endl;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        upd(x,y);
    }
}


