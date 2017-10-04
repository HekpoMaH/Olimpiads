/*
TASK: odd
LANG: C++
*/

#include<algorithm>
#include<cstdio>
int n,p=1;
long long a[1<<20];
inline bool ms(const long long &a,const long long &b)
{
    return a<b;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    std::sort(a,a+n,ms);
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])p++;
        else if(p%2)
        {
            printf("%lld\n",a[i-1]);
            return 0;
        }else p=1;
    }
}
