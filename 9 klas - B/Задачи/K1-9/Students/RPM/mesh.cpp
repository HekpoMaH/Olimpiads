#include <iostream>
using namespace std;
int main()
{
    int a,b,h;
    scanf("%d%d",&a,&b);
    if (b>a)
    {
            h=b;
            b=a;
            a=h;
    }
    if (a==b)
    {
             int ans=(a-1)*3+1;
             printf("%d\n",ans);
             return 0;
    }
    if ((a+b)%2==1)
    {
                   int ans=(a-b+1)+(b-1)*2;
                   printf("%d\n",ans);
                   return 0;
    }
    if ((a+b)%2==0)
    {
                   int ans=(a-b+1)+((b-1)/3)*6;
                   if ((b-1)%3==1) ans+=3;
                   if ((b-1)%3==2) ans+=4;
                   printf("%d\n",ans);
                   return 0;
    }
return 0;
}
