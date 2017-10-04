#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
int t,m,n,j,i,pos=0,r,k,ans,mat[124][124],korx,kory,used[124][124];
using namespace std;
struct edge
{
    int x;
    int y;
    int h;
};
queue <edge> q;
void dfs()
{
    edge a,b;
    a.x=korx;
    a.y=kory;
    a.h=0;
    q.push(a);
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        if(a.h+1<=k)
        {
            if(a.x-1>0)
            {
                if(used[a.x-1][a.y]==0)
                 {
                b.x=a.x-1;
                b.y=a.y;
                b.h=a.h+1;
                if(b.h==k){ans+=mat[b.x][b.y];}
                used[b.x][b.y]++;

                q.push(b);
                }
            }
            if(a.x+1<=m)
            {
                if(used[a.x+1][a.y]==0)
                {
                b.x=a.x+1;
                b.y=a.y;
                b.h=a.h+1;
               if(b.h==k){ans+=mat[b.x][b.y];}
                q.push(b);
                used[b.x][b.y]++;
                }
            }
            if(a.y+1<=n)
            {
                if(used[a.x][a.y+1]==0)
                {
                b.x=a.x;
                b.y=a.y+1;
                b.h=a.h+1;
                if(b.h==k){ans+=mat[b.x][b.y];}
                q.push(b);
                used[b.x][b.y]++;
                }
            }
            if(a.y-1>0)
            {
                if(used[a.x][a.y-1]==0)
                {
                b.x=a.x;
                b.y=a.y-1;
                b.h=a.h+1;
                if(b.h==k){ans+=mat[b.x][b.y];}
                q.push(b);
                used[b.x][b.y]++;
                }
            }
        }
    }
}
int main()
{
    t=1;
    cin>>m>>n>>r>>k;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++) {mat[i][j]=t;if(t==r){korx=i;kory=j;}t++;}

    dfs();
    cout<<ans<<endl;
}
