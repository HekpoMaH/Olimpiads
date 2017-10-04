#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,a[104],br;
int main()
{
    scanf("%lld",&n);scanf("%lld",&k);
    for(int i=0;i<k;i++)scanf("%lld",&a[i]);
    sort(a,a+k);
    for(int i=1;i<k;i++)
    {
        if(a[i]!=a[i-1])br++;
    }
    printf("%lld\n",n-br-1);
    return 0;
}
