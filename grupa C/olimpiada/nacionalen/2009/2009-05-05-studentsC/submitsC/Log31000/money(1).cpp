/*
TASK: money
LANG: C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200010];
int main()
{
    int n,i,j,m=1,br;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    j=0; br=2;
    for(i=2;i<n;i++)
    {
        if(a[j]+a[j+1]>a[i]) br++;
        else
        {
            if(br>m) m=br;
            while(i-j>1&&a[j]+a[j+1]<=a[i]) { j++; br--; }
            br++;
        }
    }
    if(br>m) m=br;
    if(m==2) m=1;
    printf("%d\n",m);
    return 0;
}
