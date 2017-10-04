/*
TASK: money
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[200020],n,ans;

int bin_search(int l,int r,int k)
{
    int p=r+2;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(a[mid]+a[mid+1]<=k)l=mid+1;
        else r=mid;
    }
    if(a[r]+a[r+1]>k)return p-r+1;
    return 0;
}

int main()
{
    int i;
    ans=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=2;i<n;i++)
     ans=max(ans,bin_search(0,i-2,a[i]));
    printf("%d\n",ans);
}
