#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long it[120008],a[100028];
int n;
void update(int pos,int x)
{
    while(pos<=n)
    {
        it[pos]+=x;
        pos+=pos&(-pos);
    }
}
long long find(int i,int j)
{
    long long sum1=0,sum2=0;
    while(j>=1)sum2+=it[j],j-=j&(-j);
    i--;
    while(i>=1)sum1+=it[i],i-=i&(-i);
    return (sum2-sum1);
}
void read()
{
    long long x,an;
    int l,r,k,t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);it[i]+=a[i];
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d",&l);scanf("%d",&r);
            printf("%I64d\n",it[r]-it[l-1]);
        }
        else
        {
            scanf("%d",&l);scanf("%d",&r);scanf("%d",&x);
            it[r]^=x;it[l-1]^=x;
        }
    }
}
int main()
{
    read();
    return 0;
}
