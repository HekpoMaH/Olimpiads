/*
TASK: diet
LANG: C++
*/
#include<iostream>
#include<cstdio>
using namespace std;

int a,b,c,a1,b1,c1,tmp,res,k,res2;
int ans1,ans2;

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    ans1=(a*10+b*20+c*30)/60;
    res=min(a,min(b,c));
    a-=res;
    b-=res;
    c-=res;
    if(a==0&&b==0&&c==0){printf("%d %d\n",ans1,ans2);return 0;}
    res=(a*10+b*20+c*30)/60;
    res2=(a*10+b*20+c*30)%60;
    if(c<res)
    {
        tmp=res-c;
        if(a>=tmp)
        {
            a-=tmp;
            if(a<res)ans2+=(res-a)/2;
            if(((res-a)&1))ans2++;
        }
        else
        {
            k=tmp-a+res;
            ans2+=k/2;
            if(k&1)ans2++;
        }
        
    }
    else if(a<res)
    {
        if(b<res)
        {
             if(a>=b)
             {
                    tmp=a-b;
                    a-=(tmp/3)*2;
                    b+=(tmp/3);
                    ans2+=max(res-a,res-b);
             }
             else
             {
                    k=c-res;
                    if(res2>=30)k--;
                    ans2+=k;
                    a+=k;
                    b+=k;
                    if(a<res)
                    {
                        k=res-a;
                        ans2+=k/2;
                        if(k&1)ans2++;
                    }
             }
        }
        else
        {
            k=c-res;
            if(res2>=30)k--;
            ans2+=k;
            a+=k;
            b+=k;
            if(a<res)
            {
                k=res-a;
                ans2+=k/2;
                if(k&1)ans2++;
            }
        }
    }
    else if(b<res)
    {
        tmp=a-b;
        a-=(tmp/3)*2;
        b+=(tmp/3);
        ans2+=max(res-a,res-b);
    }
    printf("%d %d\n",ans1,ans2);
}
