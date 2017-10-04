 /*
TASK:odd
LANG:C++
*/
#include<iostream>
using namespace std;
int main()
{
    long long xo=0,n,a;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&a);
      //b  printf("%lld %lld\n",i,n);
        xo=xo^a;
    }
    printf("%lld\n",xo);
    return 0;
}
    
    
