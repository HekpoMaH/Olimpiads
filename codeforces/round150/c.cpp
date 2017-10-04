#include<cstdio>
#include<set>
using namespace std;
int n,a[100004],s[1000005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]|=a[i];

    printf("%d",s[n]|s[n-6]);
    return 0;
}
