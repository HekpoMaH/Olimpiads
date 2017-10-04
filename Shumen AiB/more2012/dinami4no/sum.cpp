#include<iostream>
using namespace std;
long long dp[350][1005];
int n,s;
int main()
{
    cin>>n>>s;
    dp[0][0]=1;
    //for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<s;j++)
        {
            for(int a=0;a<=s;a++)
            {
                if(j-a*a<0)break;
                dp[i][j]+=dp[i-1][j-a*a];
            }
        }
    }
    long long br=0;
    for(int i=0;i<s;i++)
    {
        br+=dp[n][i];
    }
    cout<<br<<endl;
    return 0;
}