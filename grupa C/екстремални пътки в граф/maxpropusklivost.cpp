#include<iostream>
using namespace std;
int n,m,a[100][100],x,y,z,s,t;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    cin>>s>>t;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&j!=k&&k!=i&&a[i][j]<min(a[i][k],a[k][j]))
                {
                    a[i][j]=min(a[i][k],a[k][j]);
                }
            }
        }
    }
    cout<<a[s][t]<<endl;
    return 0;
}
/*
5 7
1 2 5
1 3 3
1 4 2
2 3 4
2 5 2
3 4 1
4 5 6
*/