/*
TASK: ship
LANG: C++
*/
#include<iostream>
using namespace std;
struct data
{
    int x,p;
};
data a[10010];
int pr=1000000000,n,t;
bool pl[10010];
void rec(int num)
{
    int i;
    if(num==n)
    {
        if(t<pr) pr=t;
        return;
    }
    for(i=0;i<n;i++)
    {
        if(pl[i]==0)
        {
            pl[a[i].p]=1;
            num++;
            if(a[a[i].p].p==i)
            {
                pl[i]=1;
                num++;
            }
            t+=a[i].x+a[a[i].p].x;
            swap(a[i],a[a[i].p]);
            rec(num);
            swap(a[i],a[a[i].p]);
            t-=(a[i].x+a[a[i].p].x);
            if(a[a[i].p].p==i)
            {
                pl[i]=0;
                num--;
            }
            num--;
            pl[a[i].p]=0;
        }
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i].x);
    for(i=0;i<n;i++) scanf("%d",&a[i].p);
    rec(0);
    cout<<pr<<'\n';
    return 0;
}
