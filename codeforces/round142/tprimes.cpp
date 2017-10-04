#include<cstdio>
#include<cmath>
using namespace std;
long long n,a,d,l;
int main()
{
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        d=sqrt(a);
        if(d*d==a)
        {
            l=0;
            for(int i=2;i*i<=d;i++)
            {
                if(d%i==0)
                {
                    l=1;
                    break;
                }
            }
            if(a==1)l=1;
            if(l==0)printf("YES\n");
        }
        else l=1;
        //printf("%I64d\n",l);
        if(l==1)printf("NO\n");
    }
    return 0;
}