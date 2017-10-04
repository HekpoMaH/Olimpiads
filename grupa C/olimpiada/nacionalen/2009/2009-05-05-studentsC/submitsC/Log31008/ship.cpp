/*
TASK: ship
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,b[10010],c[10010];
long long ans;

struct tovar
{
    int t,i1,i2;
};

tovar a[10010];

int cmp(tovar b1,tovar b2)
{
    return b1.t>b2.t;
}

int cmp2(tovar b1,tovar b2)
{
    return b[b1.i2]<b[b2.i2];
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].t);
        b[i]=a[i].t;
        a[i].i1=i;
    }
    for(i=0;i<n;i++)
     scanf("%d",&a[i].i2);
    sort(a,a+n,cmp2);
    for(i=0;i<n;i++)
     c[a[i].i1]=i;
    for(i=0;i<n;i++)
    {
        if(b[a[i].i2]>b[a[c[a[i].i2]].i2])
        {
            ans+=b[a[c[a[i].i2]].i1]+b[a[c[a[i].i2]].i2];
            swap(b[a[c[a[i].i2]].i1],b[a[c[a[i].i2]].i2]);
            a[c[a[c[a[i].i2]].i2]].i1=a[c[a[i].i2]].i1;
            a[c[a[i].i2]].i1=a[c[a[i].i2]].i2;
            swap(c[a[c[a[i].i2]].i1],c[a[c[a[c[a[i].i2]].i2]].i1]);
            ans+=a[i].t+b[a[i].i2];
            swap(b[a[i].i1],b[a[i].i2]);
            a[c[a[i].i2]].i1=a[i].i1;
            a[i].i1=a[i].i2;
            swap(c[a[i].i1],c[a[c[a[i].i2]].i1]);
        }
        if(a[i].i1!=a[i].i2&&b[a[i].i2]<b[a[i].i1])
        {
            ans+=a[i].t+b[a[i].i2];
            swap(b[a[i].i1],b[a[i].i2]);
            a[c[a[i].i2]].i1=a[i].i1;
            a[i].i1=a[i].i2;
            swap(c[a[i].i1],c[a[c[a[i].i2]].i1]);
        }
    }
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
     c[a[i].i1]=i;
    for(i=0;i<n;i++)
    {
        if(a[i].i1!=a[i].i2)
        {
            ans+=a[i].t+b[a[i].i2];
            swap(b[a[i].i1],b[a[i].i2]);
            a[c[a[i].i2]].i1=a[i].i1;
            a[i].i1=a[i].i2;
            swap(c[a[i].i1],c[a[c[a[i].i2]].i1]);
        }
    }
    cout<<ans<<"\n";
}
