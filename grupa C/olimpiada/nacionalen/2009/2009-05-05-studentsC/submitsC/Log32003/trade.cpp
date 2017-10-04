/*
TASK: trade
LANG: C++
*/
#include<cstdio>
using namespace std;
struct rib
{
    int x;
    double v;
};
rib a[100010][2];
bool used[100010],is[100010];
int q[100010];
int main()
{
    int x,y,i,j,n;
    double z;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%lf",&x,&y,&z);
        if(is[x]==0)
        {
            a[x][0].x=y;
            a[x][0].v=z*2;
            is[x]=1;
        }
        else
        {
            a[x][1].x=y;
            a[x][1].v=z*2;
        }
        if(is[y]==0)
        {
            a[y][0].x=x;
            a[y][0].v=z*2;
            is[y]=1;
        }
        else
        {
            a[y][1].x=x;
            a[y][1].v=z*2;
        }
    }
    int br=0;
    while(br<n)
    {
        int v;
        for(i=1;i<=n;i++) if(!used[i]) { v=i; break; }
        q[0]=v;
        br++;
        used[v]=1;
        int l=0,r=1;
        while(l<r)
        {
            if(!used[a[q[l]][0].x])
            {
                used[a[q[l]][0].x]=1;
                q[r]=a[q[l]][0].x;
                r++;
                br++;
            }
            if(!used[a[q[l]][1].x])
            {
                used[a[q[l]][1].x]=1;
                q[r]=a[q[l]][1].x;
                r++;
                br++;
            }
            l++;
        }
        if(r==4)
        {
            printf("impossible\n");
            return 0;
        }
    }
    printf("too many\n");
    return 0;
}
