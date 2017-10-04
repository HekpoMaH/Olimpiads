
/*
TASK:metro
LANG:C++
*/
#include<cstdio>
#define mv 100000000
using namespace std;
int a[1024][128];
int na=0,kr=99;
inline int price(int nh,int h)
{
    if(nh<h)return 7*(h-nh);
    if(nh>h)return (nh-h)*(nh-h);
    return 1;
}
int main()
{
    int n,i,h,nh,mi=mv;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&nh);
        for(h=na;h<=kr;h++)
        {
            a[i][h]=mv;
            if(h+2<100 && a[i-1][h+2]<a[i][h])
                a[i][h]=a[i-1][h+2];
            if(h+1<100 && a[i-1][h+1]<a[i][h])
                a[i][h]=a[i-1][h+1];
            if(a[i-1][h]<a[i][h])
                a[i][h]=a[i-1][h];
            if(h-1>=0 && a[i-1][h-1]<a[i][h])
                a[i][h]=a[i-1][h-1];
            a[i][h]+=price(nh,h);
            if(i==n && mi>a[i][h])mi=a[i][h];
        }
    }
    printf("%d\n",mi);
}
