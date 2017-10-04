#include<iostream>
#include<string>
using namespace std;
string a,b;
int dp[1002][1002],n,m;
int main()
{
    cin>>a;
    cin>>b;
    n=a.size();m=b.size();
    for(int i=0;i<n;i++)if(a[i]==b[0])dp[i][0]=1;
    for(int i=0;i<m;i++)if(a[0]==b[i])dp[0][i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i]!=b[j])dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
        }
    }
    cout<<n-dp[n-1][m-1]*2+m<<endl;
    return 0;
}
/**
abbcddefef
bccdefababcabc
*/