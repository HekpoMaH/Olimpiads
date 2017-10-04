#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int s,n,a[128],b,i;
    scanf("%d%d",&s,&n);
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    if(n==1){printf("%d\n",s);return 0;}
    sort(a,a+n);
    for(i=n-1;i>0;i--){if(s%a[i]==0){b=s/a[i];printf("%d\n",b);return 0;}}
    printf("3\n");
    return 0;
}
