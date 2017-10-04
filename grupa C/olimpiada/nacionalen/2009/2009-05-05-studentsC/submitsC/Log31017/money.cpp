/*
TASK:money
LANG:C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int a[262144];
int bs(int l,int r,int x)
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]<x)
        {
            if(a[mid+1]>=x)return mid;
            l=mid+1;
        }
        else r=mid-1;
    }
}
int main()
{
    int r,m=1,i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    a[n]=10000000;
    for(i=0;i<n-2;i++)
    {   
        r=bs(i,n-1,a[i]+a[i+1])-i+1;
        if(r>2 && r>m)m=r;
    }
    printf("%d\n",m);
}
