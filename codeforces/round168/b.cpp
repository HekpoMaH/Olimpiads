#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<queue>
using namespace std;
struct qu
{
    int x,y,l,a,b;
};
int n,m,a[55][55],br,used[55][55];
queue<qu> q;
char c;
void bfs(qu x)
{
    int la=0;
    qu curr;
    qu nx;;
    x.l=-1;curr=x;
    if(a[curr.x][curr.y+1]==1)
    {
        nx.x=curr.x;
        nx.y=curr.y+1;
        nx.l=curr.l+1;
        nx.a=0;
        nx.b=1;
        q.push(nx);
    }
    if(a[curr.x][curr.y-1]==1)
    {
        nx.x=curr.x;
        nx.y=curr.y-1;
        nx.l=curr.l+1;
        nx.a=0;
        nx.b=-1;
        q.push(nx);
    }
    if(a[curr.x+1][curr.y]==1)
    {
        nx.x=curr.x+1;
        nx.y=curr.y;
        nx.l=curr.l+1;
        nx.a=1;
        nx.b=0;
        q.push(nx);
    }
    if(a[curr.x-1][curr.y]==1)
    {
        nx.x=curr.x-1;
        nx.y=curr.y;
        nx.l=curr.l+1;
        nx.a=-1;
        nx.b=0;
        q.push(nx);
    }
    //q.push(x);
    while(!q.empty())
    {la=0;
        curr=q.front();
        used[curr.x][curr.y]=1;
        if(a[curr.x+curr.a][curr.y+curr.b]==1&&used[curr.x+curr.a][curr.y+curr.b]==0)
        {
            nx.x=curr.x+curr.a;
            nx.y=curr.y+curr.b;
            nx.a=curr.a;
            nx.b=curr.b;
            nx.l=curr.l;
            q.push(nx);
        }
        if(a[curr.x][curr.y+1]==1&&(curr.a!=0||curr.b!=1)&&used[curr.x][curr.y+1]==0&&curr.l==0)
        {
            nx.x=curr.x;
            nx.y=curr.y+1;
            nx.l=curr.l+1;
            nx.a=0;
            nx.b=1;
            q.push(nx);
        }
        if(a[curr.x][curr.y-1]==1&&(curr.a!=0||curr.b!=-1)&&used[curr.x][curr.y-1]==0&&curr.l==0)
        {
            nx.x=curr.x;
            nx.y=curr.y-1;
            nx.l=curr.l+1;
            nx.a=0;
            nx.b=-1;
            q.push(nx);
        }
        if(a[curr.x+1][curr.y]==1&&(curr.a!=1||curr.b!=0)&&used[curr.x+1][curr.y]==0&&curr.l==0)
        {
            nx.x=curr.x+1;
            nx.y=curr.y;
            nx.l=curr.l+1;
            nx.a=1;
            nx.b=0;
            q.push(nx);
        }
        if(a[curr.x-1][curr.y]==1&&(curr.a!=-1||curr.b!=0)&&used[curr.x-1][curr.y]==0&&curr.l==0)
        {
            nx.x=curr.x-1;
            nx.y=curr.y;
            nx.l=curr.l+1;
            nx.a=-1;
            nx.b=0;
            q.push(nx);
        }q.pop();
    }
}
int main()
{
    qu st;
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        cin>>c;if(c=='B')a[i][j]=1;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    if(a[i][j]==1)br++;
    if(br==1){
        cout<<"YES"<<endl;return 0;}
        //cout<<"A"<<endl;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    if(a[i][j]==1)
    {
        st.x=i;
        st.y=j;
        st.l=-1;
        bfs(st);
        for(int k=1;k<=n;k++)
        for(int p=1;p<=m;p++)
        if(a[k][p]==1&&used[k][p]!=1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for(int k=1;k<=n;k++)memset(used[k],0,sizeof(used[k]));
    }
    cout<<"YES"<<endl;
    return 0;
}
