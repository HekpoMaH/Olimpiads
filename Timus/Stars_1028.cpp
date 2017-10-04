#include<iostream>
#include<cstdio>
using namespace std;
int t[3200][3200];
int n,xi[32000],yi[32000];
void inc(int x,int y)
{
    int y1;
    while(x<=3200)
    {
        y1=y;
        while(y1<=3200)
        {
            t[x][y1]++;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}
int lev(int x,int y)
{
    int s=0,y1;
    while(x>0)
    {
        y1=y;
        while(y1>0)
        {
            s+=t[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return s;
    
}
int levels[32000],ll;
int main()
{
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&xi[i],&yi[i]);
        inc(xi[i],yi[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ll=lev(xi[i],yi[i])-1;
        levels[ll]++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",levels[i]);
    }
    return 0;
}