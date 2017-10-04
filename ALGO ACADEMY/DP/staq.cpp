#include<iostream>
using namespace std;
int t,n,m;
char x;
bool a[20][20];
int sol[20][20],ccol,ans;
void bfs(int x,int y)
{
    int ki=x,kj=y,br=0,mx=0,mp;
    while(1)
    {
        ki++;
        br++;
        if(ki>=n||a[ki][kj]==0||sol[ki][kj]!=0)break;
    }
    ki=x-1;
    while(1)
    {
        ki--;
        br++;
        if(ki<=1||a[ki][kj]==0||sol[ki][kj]!=0)break;
    }
    if(mx<br){mx=br;mp=1;}
    ki=x,kj=y;
    br=0;
    while(1)
    {
        kj++;
        br++;
        if(kj>=m||a[ki][kj]==0||sol[ki][kj]!=0)break;
    }
    kj=y-1;
    while(1)
    {
        kj--;
        br++;
        if(kj<=1||a[ki][kj]==0||sol[ki][kj]!=0)break;
    }
    if(mx<br){mx=br;mp=2;}
    if(mp==1)
    {
        ccol++;
        for(int i=1;i<=mp;i++)sol[x][i]=ccol;
        for(int i=mp;i<=m;i++)sol[x][i]=ccol;
    }
}
int main()
{
    cin>>t;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            if(x=='#')a[i][j]=0;
            else a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1&&sol[i][j]==0)
            {
                bfs(i,j);ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}