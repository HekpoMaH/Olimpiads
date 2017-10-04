/*
TASK:ship
LANG:C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct s
{
    int t,np;
};
struct data
{
    int t,nasp,kp;
};
bool f(const s &x,const s &y)
{
    if(x.t<y.t)return true;
    return false;
}
s b[16384];
data a[16384];
int nptkt[16384],c[16384],brc[16384];
bool used[16384];
int main()
{
    long long ddf,v,w,sb;
    int mini=1000000,br=0,i,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].t);
        if(a[i].t<mini)mini=a[i].t;
        a[i].nasp=i;
        b[i].t=a[i].t;b[i].np=i;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].kp);
        nptkt[a[i].kp]=i;
    }
    for(i=0;i<n;i++)
    {
        if(!c[i])
        {
            br++;
            x=i;
            while(a[x].kp!=i)
            {
                c[x]=br;brc[br]++;
                x=a[x].kp;    
            }
            c[x]=br;brc[br]++;
        }
    }
    sort(b,b+n,f);
    ddf=0;
    for(i=0;i<n;i++)
    {
        if(!used[c[b[i].np]])
        {
            sb=0;
            x=b[i].np;
            while(a[x].kp!=b[i].np)
            {
                sb+=a[x].t;
                x=a[x].kp;
            }
            sb+=a[x].t;
            w=mini*(brc[c[b[i].np]]+1)+sb+b[i].t;
            x=b[i].np;
            v=0;
            while(a[x].nasp!=a[x].kp)
            {
                v+=a[x].t;
                v+=a[nptkt[a[x].nasp]].t;
                swap(a[x].nasp,a[nptkt[a[x].nasp]].nasp);
            }
            if(w<v)ddf+=w;
            else ddf+=v;
            used[c[b[i].np]]=1;
        }
    }
    printf("%lld\n",ddf);
}
