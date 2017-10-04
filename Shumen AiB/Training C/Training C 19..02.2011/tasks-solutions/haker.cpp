#include <cstdio>
using namespace std;
int n,a[2048],b[2048],i,j,mx,ans=1;

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    b[n-1]=1;
    for(i=n-2;i>=0;i--)
    {
        for(j=i+1;j<n;j++)if(a[i]<=a[j] && b[j]>mx)mx=b[j];
        b[i]=mx+1;
        if(b[i]>=ans)ans=b[i];
        mx=0;
    }
    ans=n-ans;
    printf("%d\n",ans);
    return 0;
}
