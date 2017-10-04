#include<iostream>
using namespace std;
int n,a[500],dp[50003];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=50000;j>=0;j--)
        {
            if(dp[j]==1)dp[j+a[i]]=1;
        }
    }
    int s=0;
    for(int i=0;i<=50000;i++)if(dp[i]==1)s++;
    cout<<s<<endl;
    return 0;
}
