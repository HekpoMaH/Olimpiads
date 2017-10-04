/*
TASK: diet
LANG: C++
*/
#include<cstdio>
using namespace std;
int a,b,c,d,sl;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    while(a*10+b*20+c*30>=60)
    {
        bool x=0,y=0,z=0;
        d++;
        if(a>0) { a--; x=1; }
        if(b>0) { b--; y=1; }
        if(c>0) { c--; z=1; }
        //printf("----\n%d %d %d\n",a,b,c);
        if(!x)
        {
            if(b==0)
            {
                sl++;
                if(y)
                {
                    x=1;
                    b--;
                    a++;
                }
                else
                {
                    x=1; y=1;
                    c--;
                }
            }
            else
            {
                sl++;
                x=1;
                a++;
                b--;
            }
        }
        if(!y)
        {
            if(a<2)
            {
                sl++;
                c--;
                a++;
                y=1;
            }
            else
            {
                a-=2;
                y=1;
            }
        }
        if(!z)
        {
            if(a>=1&&b>=1)
            {
                z=1;
                a--;
                b--;
            }
            else
            {
                if(b<1)
                {
                    a-=3;
                    z=1;
                }
                else
                if(a<1)
                {
                    sl++;
                    b-=2;
                    a++;
                }
            }
        }
        //printf("%d %d\n%d %d %d\n",d,sl,a,b,c);
    }
    printf("%d %d\n",d,sl);
    return 0;
}
