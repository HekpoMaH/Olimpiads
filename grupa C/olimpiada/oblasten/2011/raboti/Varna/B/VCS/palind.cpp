#include<iostream>
using namespace std;
bool seq[1<<14];
int n, dp[1<<14], p[1<<14];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&seq[i]);
    dp[0]=1;
    if(seq[0] == seq[1]) dp[1] = 1; else dp[1]=2;
    if(seq[0] == seq[2]) dp[2] = 1; else dp[2]=dp[1]+1;
    for(int i=3;i<n;i++)
    {
        dp[i]=dp[i-1]+1;
        if(seq[i]==seq[i-1]) dp[i]=min(dp[i-2]+1, dp[i]);
        if(seq[i]==seq[i-2]) dp[i]=min(dp[i-3]+1, dp[i]);

        for(int j=0;j<i-2;j++)
        {
            bool isP = true;
            for(int k=j;k<i;k++) if(seq[k]!=seq[(i+j)-k]) {isP=false; break;}
            if(isP)
            {
                dp[i] = min(dp[i], (j?dp[j-1]:0)+1);
                p[i]=j-1;
            }
        }
    }
    cout<<dp[n-1]<<endl;
    int pt=p[n-1];
    while(pt>0){cout<<pt+1<<" "; pt=p[pt];} cout<<endl;
    return 0;
}
