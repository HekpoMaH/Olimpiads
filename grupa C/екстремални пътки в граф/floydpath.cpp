#include<iostream>
#include<cstring>
using namespace std;
int a[100][100],ks[100][100];
int n,m,x,y,z,s,t,first,second;
void prinpath(int i,int j)
{
    if(ks[i][j]==-1){cout<<i<<" "<<j;return;}
    prinpath(i,ks[i][j]);cout<<endl;prinpath(ks[i][j],j);cout<<endl;
}
int main()
{
    memset(a,31,sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    memset(ks,-1,sizeof(ks));
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&j!=k&&i!=k&&a[i][j]>a[i][k]+a[k][j])
                {
                    a[i][j]=a[i][k]+a[k][j];
                    ks[i][j]=k;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cin>>first>>second;
    prinpath(first,second);
    return 0;
}
/*
6 7
1 5 25
1 6 -10
2 1 20
2 5 5
2 3 -30
4 2 60
5 4 15
*/
