#include<cstdio>
#define ll long long
using namespace std;

int n;
ll a,d[11][20],b,c;

int main()
{
    int i,k;
    scanf("%d",&n);
    for(;n;n--)
    {
        scanf("%lld",&b);
        a=b;
        i=0;
        while(b)
        {
            k=(int)(b%10);
            d[k][i]^=a;
            b>>=1;
            i++;
        }
        c^=a;
    }
    b=0;
    for(i=0;i<=9;i++)
     for(k=0;k<=19;k++)
      if(d[i][k]&&d[i][k]!=c&&d[i][k]>b)b=d[i][k];
    a=b^c;
    printf("%lld ",a);
    printf("%lld\n",b);
}
