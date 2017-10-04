#include<iostream>
#include<cstring>
using namespace std;
int a[100][100],d[100];
int n,m,x,y,z,starter;
int main()
{
    memset(a,31,sizeof(a));
    //cout<<a[1][1]<<endl;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    for(int i=1;i<=n;i++)a[i][i]=0;
    cin>>starter;
    for(int i=1;i<=n;i++)d[i]=a[starter][i];
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
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    cout<<endl;
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
2
*/
