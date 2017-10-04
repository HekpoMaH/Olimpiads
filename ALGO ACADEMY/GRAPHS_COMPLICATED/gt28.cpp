#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int l;
int a[1000][1000],ks[1000][1000],pp[1000][1000];
void prinpath(int x1,int x2)
{
    if(ks[x1][x2]==-1){l+=a[x1][x2];return;}
    prinpath(x1,ks[x1][x2]);prinpath(ks[x1][x2],x2);
}
int n,m,x,y,z,s,t,ee;
int main()
{
    memset(a,31,sizeof(a));memset(ks,-1,sizeof(ks));ee=a[0][0];
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d,%d,%d",&x,&y,&z);
        //cout<<x<<" "<<y<<" "<<z<<endl;
        a[x+1][y+1]=z;pp[x+1][y+1]=1;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&j!=k&&i!=k&&a[i][j]>a[i][k]+a[k][j])
                {
                    a[i][j]=a[i][k]+a[k][j];pp[i][j]=1;
                }
                //cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
    cout<<0<<endl;
    for(int i=2;i<=n;i++)
    {
        if(pp[1][i]==0){cout<<"Unreachable!"<<endl;continue;}
        l=0;
        //if(l<0){cout<<"Black hole!"<<endl;continue;}
        cout<<a[1][i]<<endl;
    }
    return 0;
}

