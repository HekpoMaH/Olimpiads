#include<iostream>
#include<set>
using namespace std;
set<long long> s;long long n,k,mn=9999099999909;
long long a[1000009],sum[1000009],mb;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){cin>>a[i];if(i<=k)s.insert(a[i]);sum[i]=sum[i-1]+a[i];}
    for(int i=k;i<=n;i++)
    {
        if(mn>sum[i]-sum[i-k]-k*(*s.begin()))
        {
            mn=sum[i]-sum[i-k]-k*(*s.begin());
            mb=i-k+1;
        }
        s.erase(a[i]);s.insert(a[i]);
    }
    cout<<mn<<endl<<mb<<endl;//what
}
