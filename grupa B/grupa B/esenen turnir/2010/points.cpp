#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,t;
long long ans,vs;
long long a[40];
vector<long long> v;
void bs(long long s)
{
    long long l=0,r=vs-1;
    long long md,g=vs;
    while(l<=r)
    {
        md=(l+r)/2;
        if(v[md]+s>=t)r=md-1,g=md;
        else l=md+1;
    }
    ans+=vs-g;
}
int main()
{
    cin>>n>>t;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long mid=n/2,sum;
    for(long long i=0;i<(1<<mid);i++)
    {
        sum=0;
        for(long long j=1;j<=mid;j++)
        {
            if((i&(1<<j-1))!=0)sum+=a[j];
        }
        v.push_back(sum);
    }
    sort(v.begin(),v.end());
    vs=v.size();
    long long rem;
    rem=n-mid;
    for(long long i=0;i<(1<<rem);i++)
    {
        sum=0;
        for(long long j=1;j<=rem;j++)
        {
            if((i&(1<<j-1))!=0)sum+=a[j+mid];
        }
        bs(sum);
    }
    cout<<ans<<endl;
    return 0;
}

