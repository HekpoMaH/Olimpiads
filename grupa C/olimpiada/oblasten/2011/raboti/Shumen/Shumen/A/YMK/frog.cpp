#include<iostream>
#include<vector>
using namespace std;

struct point
{
    int x;
    int y;
};

int n;
point a[16];
int dist[16][16];
int mxl=40000;
int used[16];

void dfs(int ln, int br, int vis[16],int tek)
{
    vis[tek]=1;
    if(br==n)
    {
        if(ln<mxl)mxl=ln;
        vis[tek]=0;
        return;
    }
    for(int i=1;i<=2*n;i++)
    {
        if(vis[i]==0)
        {
            //cout<<"from "<<tek<<" to "<<i<<" with ln "<<ln+dist[tek][i]<<endl;
            dfs(ln+dist[tek][i],br+1,vis,i);
        }
    }
    vis[tek]=0;
}

int main()
{
    int v1,v2;
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++)
    {
        scanf("%d%d",&v1,&v2);
        a[i].x=v1;
        a[i].y=v2;
        dist[0][i]=max(abs(v1),abs(v2));
        dist[i][0]=dist[0][i];
    }
    for(int i=1;i<=n*2;i++)
        for(int j=i+1;j<=n*2;j++)
        {
            dist[i][j]=max(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y));
            dist[j][i]=dist[i][j];
        }
    for(int i=1;i<=2*n;i++)
    {
        //cout<<"wtf"<<endl;
        dfs(dist[i][0],1,used,i);
    }
    printf("%d\n",mxl);
    return 0;
}

/*

2
1 1
3 5
4 6
8 2

4
-1 -1
-2 -2
-3 -1
1 1
5 5
6 6
5 7
4 6

6
3 7
1000 516
-124 -512
98 -988
666 696
69 -69
550 888
111 -1
0 6
553 1
-5 -69
-5 -69
*/


