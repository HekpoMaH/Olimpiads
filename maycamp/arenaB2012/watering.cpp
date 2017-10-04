#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,d,l,a[100003],righ,lef,mid,ans;
bool check(int x)
{
    int  v[100000];
    for(int i=1;i<=x;i++)
    {
        v[i]=a[i];
    }
    sort(v+1,v+x+1);
    v[0]=0;
    v[x+1]=l;
    for(int i=0;i<=n;i++)
    {
        if(v[i+1]-v[i]>d)return false;
    }
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&l,&d);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    righ=n;
    lef=1;
    ans=n+1;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        if(check(mid))
        {
            if(mid<ans)ans=mid;
            righ=mid-1;
        }
        else lef=mid+1;
    }
    if(ans==n+1)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}