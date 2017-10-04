/*
TASK:trade
LANG:C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
bool used[100100];
struct pa
{
    int x;
    double y;
};
pa nei[100100][3];
int n;
int main()
{
    int a,b;
    double c;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%lf",&a,&b,&c);
        nei[a][(++nei[a][0].x)].x=b;
        nei[b][(++nei[b][0].x)].x=a;
        nei[a][(nei[a][0].x)].y=c;
        nei[b][(nei[b][0].x)].y=c;
    }
    if(n&1)
    {
        used[1]=1;
        int x=1,y=1;
        double sum=0,osum=0;
        while(1)
        {
            if(!used[nei[x][1].x])
            {
                if(y%2==0) osum+=nei[x][1].y;
                sum+=nei[x][1].y;
                used[nei[x][1].x]=1;
                y++;
                x=nei[x][1].x;
                continue;
            }else
            if(!used[nei[x][2].x])
            {
                if(y%2==0) osum+=nei[x][2].y;
                sum+=nei[x][2].y;
                used[nei[x][2].x]=1;
                y++;
                x=nei[x][2].x;
                continue;
            }else
            {
                int k;
                if(nei[x][1].x==1)k=1;else k=2;
                sum+=nei[x][k].y;
                break;
            }
        }
      //  printf("%lf  %lf\n",sum,osum);
        memset(used,0,sizeof(used));
        nei[1][0].y=sum-2*osum;
        x=1;
        while(1)
        {
            if(!used[nei[x][1].x])
            {
                used[nei[x][1].x]=1;
                nei[nei[x][1].x][0].y=2*nei[x][1].y-nei[x][0].y;
                x=nei[x][1].x;
                continue;
            }else
            if(!used[nei[x][2].x])
            {
                used[nei[x][2].x]=1;
                nei[nei[x][2].x][0].y=2*nei[x][2].y-nei[x][0].y;
                x=nei[x][2].x;
                continue;
            }else
            {
                break;
            }
        }
        printf("%.2lf",nei[1][0].y);
        for(int i=2;i<=n;i++)
        printf(" %.2lf",nei[i][0].y);
        printf("\n");
        return 0;
    }else
    {
        int x,y;
        double stack[100100];
        x=1;y=0;
        while(1)
        {
            if(!used[nei[x][1].x])
            {
                if(y!=0)
                {
                    if(nei[x][1].y==stack[y-1])
                    y--;else stack[y++]=nei[x][1].y;
                }else stack[y++]=nei[x][1].y;
                used[nei[x][1].x]=1;
                x=nei[x][1].x;
                continue;
            }else
            if(!used[nei[x][2].x])
            {
                if(y!=0)
                {
                    if(nei[x][2].y==stack[y-1])
                    y--;else stack[y++]=nei[x][2].y;
                }else stack[y++]=nei[x][2].y;
                used[nei[x][2].x]=1;
                x=nei[x][2].x;
                continue;
            }else
            {
                int k;
                if(nei[x][1].x==1)k=1;else k=2;
                if(y!=0)
                {
                    if(nei[x][k].y==stack[y-1])
                    y--;else stack[y++]=nei[x][k].y;
                }else stack[y++]=nei[x][k].y;
                break;
            }
        }
        if(y!=0) printf("impossible\n");
        else printf("too many\n");
        return 0;
    } 
    return 0;
}
