#include<iostream>
#include<string>
using namespace std;
string s;
long long k,c,dp[82][82],zpr;
int main()
{
    cin>>s;
    dp[0][0]=1;
    int n=s.size();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(s[i-1]=='(')
            {
                if(j==-1)zpr=0;
                else zpr=dp[i-1][j-1];
            }
            if(s[i-1]==')')zpr=dp[i-1][j+1];
            if(s[i-1]=='?')zpr=dp[i-1][j+1]+dp[i-1][j-1];
            dp[i][j]=zpr;
        }
    }
     
    cout<<dp[n][0]<<endl;
    return 0;
}