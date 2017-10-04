#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,a[104],br;
int main()
{
    scanf("%I64d",&n);scanf("%I64d",&k);
    for(int i=0;i<k;i++)scanf("%I64d",&a[i]);
    sort(a,a+k);
    for(int i=1;i<k;i++)
    {
        if(a[i]!=a[i-1])br++;
    }
    printf("%I64d",n-br-1);
    return 0;
}
