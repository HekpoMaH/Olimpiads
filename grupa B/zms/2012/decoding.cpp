#include<bits/stdc++.h>
using namespace std;
long long dp[100];
string s;
int main()
{
    cin>>s;
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=s.size();i++)
    {
        if(s[i-1]!='0')
        {
            dp[i]+=dp[i-1];
        }
            if(10<=(s[i-2]-'0')*10+s[i-1]-'0'&&(s[i-2]-'0')*10+s[i-1]-'0'<=26)
            {
                dp[i]+=dp[i-2];
            }

    }
    cout<<dp[s.size()]<<endl;
}
