#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100006],used[13009],n,k,ans1,ans2=n+1;
bool test(int f)
{
    int br=0;
    //cout<<"ch"<<" "<<f<<endl;
    memset(used,0,sizeof(used));
    for(int i=1;i<=f;i++)
    {
        if(!used[a[i]])
        {
            used[a[i]]++;
            br++;
            if(br==k){ans1=1;ans2=i;return true;}
        }
        else used[a[i]]++;
    }
    for(int i=f+1;i<=n;i++)
    {
        if(used[a[i-f]]>=1)used[a[i-f]]--;
        if(used[a[i-f]]==0)br--;
        if(used[a[i]]==0)br++;
        used[a[i]]++;
        if(br>=k){ans1=i-f+1;ans2=i;return true;}
    }
    return false;
}
void solve()
{
    int lef=1,righ=n,mid;
    while(lef<=righ)
    {
        mid=(righ+lef)/2;
        if(test(mid)==true)righ=mid-1;
        else lef=mid+1;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    solve();
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}