#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
int a[100004],b[100004];
bool check(int len)
{
    int ind=0,rem=k;
    for(int i=0;i<n;i++)
    {
        if(rem<=0)ind++, rem=k;
        while(ind<m&&b[ind]<a[i]-len)ind++,rem=k;
        if(ind>=m)return false;
        if(a[i]<b[ind]-len)return false;
        rem--;
    }
    return true;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    int left=0,right=1000001,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        //cout<<mid<<" "<<check(mid)<<endl;
        if(check(mid))right=mid-1;
        else left=mid+1;
    }
    if(right==1000001)cout<<-1<<endl;
    else cout<<right+1<<endl;
    return 0;
}