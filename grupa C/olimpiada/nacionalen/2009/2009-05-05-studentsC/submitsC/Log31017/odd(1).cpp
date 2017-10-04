/*
TASK:odd
LANG:C++
*/
#include<cstdio>
using namespace std;
int main()
{
    long long x,z;
    int i,n;
    scanf("%d",&n);
    scanf("%lld",&z);
    for(i=1;i<n;i++)
    {
        scanf("%lld",&x);
        z^=x;
    }
    printf("%lld\n",z);
}
