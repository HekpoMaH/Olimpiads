#include<stdio.h>
using namespace std;
int used[2001],b[2001],a[2001][2001];
int main()
{
    int x,y,n,m,i,ma=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
         scanf("%d %d",&x,&y);
        a[x][0]++;
        a[x][a[x][0]]=y;
        a[y][0]++;
        a[y][a[y][0]]=y;
    }
    int st=0,cur=0,free=1,lev=0,nextl=1,d=0;
    b[0]=1;
    used[1]=1;
    st=0;
    while(1==1)
    {
        for(i=1;i<=a[b[cur]][0];i++)
        {
            if(used[a[b[cur]][i]]==0)
            {
                used[a[b[cur]][i]]=1;
                b[free]=a[b[cur]][i];
                free++; st++;
            }
        }
        cur++;
        if(cur==nextl)
        {
            if(st>ma) ma=st;
            st=0;
            cur=nextl; nextl=free;
        }
        if(cur==free) break;
    }
    printf("%d\n",ma);
    return 0;
}
