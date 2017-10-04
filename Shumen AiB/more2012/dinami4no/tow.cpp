#include<iostream>
using namespace std;
struct dd
{
    int sz,te,he;
};
dd dp[252];
int n,s[252],h[252],t[252];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>h[i]>>t[i];
    }
    dp[0].sz=92443;dp[0].te=51334;dp[0].he=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s[i]<dp[j].sz&&t[i]<dp[j].te)
            {
                if(dp[i].he<dp[j].he+h[i])
                {
                    dp[i].he=dp[j].he+h[i];
                    dp[i].te=t[i];
                    dp[i].sz=s[i];
                }
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<dp[i].sz<<" "<<dp[i].te<<" "<<dp[i].he<<endl;
    }*/
    cout<<dp[n].he<<endl;
    return 0;
}