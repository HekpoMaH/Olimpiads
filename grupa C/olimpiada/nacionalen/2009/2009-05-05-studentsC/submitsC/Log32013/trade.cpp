/*
TASK:trade
LANG:C++
*/
#include<cstdio>
using namespace std;
struct data
{
    int s;
    double cena,cr;
};
data a[131072];
int main()
{
    int n,i,x,y;
    double t,sb=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%lf",&x,&y,&t);
        sb+=t;
        if(!a[x].s)
        {
            a[x].s=y;
            a[x].cr=t;
        }
        else
        {
            a[y].s=x;
            a[y].cr=t;
        }
    }
    x=1;
    bool p=1;
    double g=0;
    while(a[x].s!=1)
    {
        if(p)g+=a[x].cr*2;
        x=a[x].s;
        p^=1;
    }
    if(n%2)
    {
        a[x].cena=sb-g;
        y=x;
        while(a[y].s!=x)
        {
            a[a[y].s].cena=a[y].cr*2-a[y].cena;
            y=a[y].s;
        }
        for(i=1;i<n;i++)printf("%.2lf ",a[i].cena);
        printf("%.2lf\n",a[n].cena);
    }
    else
        if(g==sb)printf("too many\n");
        else printf("impossible\n");
}
