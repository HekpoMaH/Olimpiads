#include<iostream>
using namespace std;
int a[100][100],x,y,z,m,n,s,l,used[100];
void dfs(int i)
{
    if(l==1)return;
    for(int j=1;j<=n;j++)
    {
        if(a[i][j]!=0&&used[j]==1){l=1;return;}
        if(a[i][j]!=0&&used[j]==0)
        {
            used[j]=1;
            dfs(j);
            used[j]=0;
        }
    }
}
int main()
{
    cin>>m>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        if(a[x][y]!=0){cout<<"YES"<<endl;return 0;}
        if(x==y){cout<<"YES"<<endl;return 0;}
        a[x][y]=z;a[y][x]=z;
    }
    if(l==1){cout<<"YES"<<endl;return 0;}
    cout<<"NO"<<endl;
    return 0;    
}