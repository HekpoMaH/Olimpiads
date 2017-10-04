#include<bits/stdc++.h>
using namespace std;
int n;
int p[10009],sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i],sum+=p[i];
    if(sum%n!=0){cout<<-1<<endl;return 0;}
    sum/=n;
    int diff,ans=-100;
    for(int i=1;i<=n;i++)
    {
        diff=sum-p[i];
        p[i]+=diff;
        p[i+1]-=diff;
        ans=max(ans,abs(diff));
    }
    cout<<ans<<endl;
}
