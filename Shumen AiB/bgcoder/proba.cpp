#include<iostream>
#include<cstdio>
using namespace std;
int t[32000];
int n,x,y;
int lev(int x)
{
    int s=0;
    while(x>=0)
    {
        s+=t[x];
        if(x==0)break;
        x-=(x&-x);
    }
    return s;
}
void inc(int x)
{
    while(x<=32000)
    {
        t[x]++;
        x+=(x&-x);
        if(x==0)break;
    }
}
int levels[32000];
int main()
{
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        inc(x);
        levels[lev(x)-1]++;
    }
    //cout<<lev(5)<<endl;
    for(int i=0;i<n;i++)
    {
        printf("%d\n",levels[i]);
    }
    return 0;
}