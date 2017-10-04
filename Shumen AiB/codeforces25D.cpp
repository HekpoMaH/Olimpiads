#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1111;
struct edge
{
    int x,y;
}edges[MAXN];
struct reconstruction
{
    int a,b,c,d;
}answer[MAXN];
int n,cnt;
int parent[MAXN],Size[MAXN];
void read()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
        Size[i]=1;
    }
    for(i=1;i<n;i++)
        scanf("%d%d",&edges[i].x,&edges[i].y);
}
int findSet(int x)
{
    if(parent[x]==x)return x;
    return parent[x]=findSet(parent[x]);
}
void mergeSets(int x,int y)
{
    if(Size[x]<Size[y])swap(x,y);
    parent[y]=x;
    Size[x]+=Size[y];
}
void solve()
{
    int i,j;
    int parent1,parent2;
    for(i=1;i<n;i++)
    {
        parent1=findSet(edges[i].x);
        parent2=findSet(edges[i].y);
        if(parent1!=parent2)
            mergeSets(parent1,parent2);
        else
        {
            cnt++;
            answer[cnt].a=edges[i].x;
            answer[cnt].b=edges[i].y;
        }
    }
    int newcnt=0;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
        {
            parent1=findSet(i);
            parent2=findSet(j);
            if(parent1!=parent2)
            {
                mergeSets(parent1,parent2);
                newcnt++;
                answer[newcnt].c=i;
                answer[newcnt].d=j;
            }
        }
    printf("%d\n",cnt);
    for(i=1;i<=cnt;i++)
        printf("%d %d %d %d\n",answer[i].a,answer[i].b,answer[i].c,answer[i].d);
}
int main()
{
    read();
    solve();
}

