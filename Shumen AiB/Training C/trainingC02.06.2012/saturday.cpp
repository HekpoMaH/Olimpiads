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
    int l=0,ri=a[n-1],mid,ans;
    while(l<=ri)
    {
        mid=l+ri;mid/=2;
        if(check(mid))ans=mid,ri=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}