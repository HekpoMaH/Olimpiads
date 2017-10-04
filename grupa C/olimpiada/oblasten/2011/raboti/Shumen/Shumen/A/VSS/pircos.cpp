#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long a[2][64];
void f(long long x)
{
    int i=0;
    long long tmp;
    tmp=x;
    while(tmp)
    {
        if(tmp%2)
            a[1][i]^=x;
        else
            a[0][i]^=x;
        i++;
        tmp/=2;
    }
}
int main()
{
    int i;
    long long e;
    long long s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&e);
        s^=e;
        f(e);
    }
    int j;
    long long tx=0;
    for(i=0;i<2;i++)
    {
        for(j=0;j<64;j++)
            if(a[i][j] && a[i][j]!=s)
            {
                tx=a[i][j];
                break;
            }
        if(j<16)
            break;
    }
    for(i=0;i<2;i++)
        for(j=0;j<64;j++)
            if(a[i][j]!=0 && a[i][j]!=s && a[i][j]!=tx)
            {
                if(tx<a[i][j])
                    printf("%lld %lld\n",tx,a[i][j]);
                else
                    printf("%lld %lld\n",a[i][j],tx);
                return 0;
            }
    return 0;
}
