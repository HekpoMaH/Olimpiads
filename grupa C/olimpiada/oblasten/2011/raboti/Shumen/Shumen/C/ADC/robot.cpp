#include<cstdio>
#include<queue>
using namespace std;
int n,m,k,r,a[1024][1024],used[1024],im,in,ans;
struct prom
{
    int x,y;
};
queue<prom> q;
void read()
{
    int i,j,o=0;
    scanf("%d%d%d%d",&n,&m,&r,&k);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        a[i][j]=++o;
        if(o==r)
        {
            im=i;
            in=j;
        }
    }
}
void bfs()
{
    prom b,c;
    int br=0;
    b.x=im;
    b.y=in;
    q.push(b);
    while(!q.empty())
    {
        br++;
        b=q.front();
        q.pop();
        if(!used[a[b.x+1][b.y]]&&a[b.x+1][b.y])
        {
            if(br>=k)
            {
                ans+=a[b.x+1][b.y];
                used[a[b.x+1][b.y]]=1;
            }
            else
            {
                c.x=b.x+1;
                c.y=b.y;
                q.push(c);
            }
        }
        if(!used[a[b.x-1][b.y]]&&a[b.x-1][b.y])
        {
            if(br>=k)
            {
                ans+=a[b.x-1][b.y];
                used[a[b.x-1][b.y]]=1;
            }
            else
            {
                c.x=b.x-1;
                c.y=b.y;
                q.push(c);
            }
        }
        if(!used[a[b.x][b.y+1]]&&a[b.x][b.y+1])
        {
            if(br>=k)
            {
                ans+=a[b.x][b.y+1];
                used[a[b.x][b.y+1]]=1;
            }
            else
            {
                c.x=b.x;
                c.y=b.y+1;
                q.push(c);
            }
        }
        if(!used[a[b.x][b.y-1]]&&a[b.x][b.y-1])
        {
            if(br>=k)
            {
                ans+=a[b.x][b.y-1];
                used[a[b.x][b.y-1]]=1;
            }
            else
            {
                c.x=b.x;
                c.y=b.y-1;
                q.push(c);
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    read();
    bfs();
    return 0;
}