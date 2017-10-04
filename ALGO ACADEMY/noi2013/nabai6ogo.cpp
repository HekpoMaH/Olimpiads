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
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if((sum[i]-sum[j-1])%n==0)
            {
                //cout<<j<<" "<<i<<endl;
                if(ans1==-1)
                {
                    ans1=j;ans2=i-j+1;
                }
                else if(ans1>i)
                {
                    ans1=j;ans2=i-j+1;
                }
            }
        }
    }
    cout<<ans1-1<<endl<<ans2<<endl;
}
