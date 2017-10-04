#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct point
{
    int x,y;
};
point make_point(int q,int w)
{
    point e;
    e.x=q;
    e.y=w;
    return e;
}
int n;
point p[16];
int a[16][16];
int comb[16];
int used[16];
int ans=999999999;
vector<int>v;
int dist(point z,point h)
{
    return max(abs(z.x-h.x),abs(z.y-h.y));
}
void calc()
{
    int i;
    int sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=a[comb[i-1]][comb[i]];
//        printf("%d ",comb[i]);
    }
//    printf("   %d \n",sum);
    if(ans>sum)
    {/*
        for(i=1;i<=n;i++)
            printf("%d+",a[comb[i]][comb[i-1]]);
        printf("@   ");
        for(i=1;i<=n;i++)
            printf("%d ",comb[i]);
        printf("\n");*/
        ans=sum;
    }
}
void f(int pos)
{
    int i;
    if(pos>n)
    {
        calc();
        return ;
    }
    for(i=1;i<=n*2;i++)
        if(used[i]==0)
        {
            used[i]=1;
            comb[pos]=i;
            f(pos+1);
            used[i]=0;
        }
}
int main()
{
    scanf("%d",&n);
    int i,j,k,t,g;
    p[0].x=0;
    p[0].y=0;
    for(i=1;i<=n*2;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    for(i=0;i<=2*n;i++)
        for(j=i+1;j<=2*n;j++)
        {
            a[i][j]=dist(p[i],p[j]);
            a[j][i]=a[i][j];
        }
    
    f(1);
    printf("%d\n",ans);
    return 0;
}
