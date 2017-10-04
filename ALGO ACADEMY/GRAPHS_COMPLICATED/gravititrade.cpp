#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int l;
int a[1000][1000],d[1000],pp[1000][1000];

int n,m,x,y,z,s,t,ee;
int main()
{
    memset(d,31,sizeof(d));memset(a,31,sizeof(a));ee=d[0];
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d,%d,%d",&x,&y,&z);
        //cout<<x<<" "<<y<<" "<<z<<endl;
        a[x+1][y+1]=z;pp[x+1][y+1]=1;
    }
    for(int i=1;i<=n;i++)a[i][i]=0,d[i]=a[1][i];
    for(int k=1;k<=n-2;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i]=min(d[i],d[j]+a[j][i]);
            }
        }
    }
    //cout<<0<<endl;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==ee){cout<<"Unreachable!"<<endl;continue;}
        l=0;
        if(d[i]+a[i][1]<0)cout<<"Black hole!"<<endl;
        cout<<d[i]<<endl;
    }
    return 0;
}
