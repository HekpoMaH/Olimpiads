#include<iostream>
#include<algorithm>
using namespace std;
int r,c,n,a[100005];
bool check(int f)
{
    int first=0,last=0,br=0,diff,group=0;
    while(1)
    {
        if(last==n)break;
        if(br>=r)break;
        diff=a[last]-a[first];
        if(diff<=f)
        {
            group++;last++;
        }
        else
        {
            group--;first++;
        }
        if(group==c)
        {
            br++;group=0;first=last;
        }
    }
    //cout<<f<<" "<<br<<endl;
    if(br==r)return true;
    return false;
}
int main()
{
    cin>>n>>r>>c;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int left=0,right=a[n-1],mid,ans;
    while(left<=right)
    {
        mid=left+right;mid/=2;
        if(check(mid))ans=mid,right=mid-1;
        else left=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}