#include<bits/stdc++.h>
using namespace std;
int a[100][24],n,m,k,used[100][25];
int broib;
void dfs(int i,int j)
{
    used[i][j]=1;
    if(used[i-1][j]==0&&a[i-1][j]==1&&i-1>=1)dfs(i-1,j);
    if(used[i][j-1]==0&&a[i][j-1]==1&&j-1>=1)dfs(i,j-1);
    if(used[i+1][j]==0&&a[i+1][j]==1&&i+1<=n)dfs(i+1,j);
    if(used[i][j+1]==0&&a[i][j+1]==1&&j+1<=m)dfs(i,j+1);
}
void chek(int x)
{
    int br=0;//cout<<"x="<<x<<endl;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((1<<br)&x)a[i][j]=1;
            br++;
            //cout<<a[i][j];
        }//cout<<endl;
    }//cout<<endl;
    memset(used,0,sizeof(used));
    int brv=0;//broi vlizzaniq
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(used[i][j]==0&&a[i][j]==1)
            {
                dfs(i,j);
                brv++;
            }
            if(brv>1)break;
        }
        if(brv>1)break;
    }
    if(brv==1)broib++;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<(1<<(n*m));i++)
    {
        chek(i);
    }
    cout<<broib%k<<endl;
}
