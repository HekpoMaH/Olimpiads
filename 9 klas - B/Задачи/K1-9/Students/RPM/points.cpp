#include <iostream>
using namespace std;

int main()
{
    unsigned long long dp[64];
    int n,k;
    int i,j;
    scanf("%d%d",&n,&k);
    for (i=0;i<64;i++)
        dp[i]=0;
    dp[n]=1;
    for (i=n-1;i>0;i--)
    {
        for (j=i+1;j<=i+k;j++)
        {
            dp[i]+=dp[j];
            if (j==n) break;
        }
        }
    cout<<dp[1]<<endl;
return 0;
}
