#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int used[509][509],br;
int ans[509][509];
void tadd(int x,int y,queue<pair<int,int> > &qu)
{
    int bro=0;
    if(used[x-1][y]>=1)bro++;
    if(used[x+1][y]>=1)bro++;
    if(used[x][y-1]>=1)bro++;
    if(used[x][y+1]>=1)bro++;
    if(bro>=3||x==1||x==n||y==1||y==m)qu.push(make_pair(x,y));
}
void output()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ans[i][j]==0)cout<<'.';
            else if(ans[i][j]==1)cout<<'#';
            else cout<<'X';
        }
        cout<<endl;
    }
}
void bfs(int x,int y)
{
    used[x][y]=1;
    //cout<<x<<" "<<y<<" "<<br<<endl;
    if(br>=k)
    {
        output();exit(0);
    }
    if(used[x-1][y]==0)bfs(x-1,y);
    if(used[x+1][y]==0)bfs(x+1,y);
    if(used[x][y-1]==0)bfs(x,y-1);
    if(used[x][y+1]==0)bfs(x,y+1);
    ans[x][y]=2;
    br++;
    if(br>=k)
    {
        output();exit(0);
    }
}
int main()
{
    string s;
    cin>>n>>m>>k;used[0][0]=used[0][m+1]=used[n+1][0]=used[n+1][m+1]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='#')used[i][j+1]=1,ans[i][j+1]=1;
            used[0][j+1]=used[n+1][j+1]=1;
        }
        used[i][0]=used[i][m+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(used[i][j]==0)bfs(i,j);
        }
        //cout<<endl;
    }
}
/*
3 3 5
...
...
...
*/
