#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<queue>
#include<cmath>
#include<string>
using namespace std;
int n;
long long a[1000009],sum[1000009],ans1=-1,ans2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        if(sum[i]%n==0)
        {
            cout<<0<<" "<<i<<endl;return 0;
        }
    }
    cout<<ans1-1<<endl<<ans2<<endl;
}

