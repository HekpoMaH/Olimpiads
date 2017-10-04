#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s,s1;
int dp[102][102],pr[102][102],prr;
int main()
{
    cin>>s>>s1;
    for(int i=0;i<=s.size();i++)
    {
        dp[i][0]=i;
        pr[i][0]=2;
    }
    for(int i=0;i<=s1.size();i++)
    {
        dp[0][i]=i;
        pr[0][i]=1;
    }int mn;
    //cout<<s.substr(1,4)<<endl;
    for(int i=1;i<=s.size();i++)
    {
        for(int j=1;j<=s1.size();j++)
        {
            prr=-1;
            mn=999999;
            if(dp[i-1][j]+1<mn)mn=dp[i-1][j]+1,prr=1;
            if(dp[i][j-1]+1<mn)mn=dp[i][j-1]+1,prr=2;
            if(s[i-1]==s1[j-1]&&mn>dp[i-1][j-1])mn=dp[i-1][j-1],prr=3;
            if(s[i-1]!=s1[j-1]&&mn>dp[i-1][j-1]+1)mn=dp[i-1][j-1]+1,prr=4;
            dp[i][j]=mn;
            pr[i][j]=prr;
        }
    }
    pr[0][0]=-1;
    cout<<dp[s.size()][s1.size()]<<endl;
    stack<int> ss;
    //cout<<s.size()<<endl;
    int i=s.size(),j=s1.size(),br=0;
    while(i>=0||j>=0)
    {
        br++;
        //cout<<i<<" "<<j<<endl;
        if(i==0)j--;
        else if(j==0)i--;
        if(i==0&&j==0)break;
        //if(br==19)return 0;
        ss.push(pr[i][j]);
        if(pr[i][j]==1)i--;
        else if(pr[i][j]==2)j--;
        else if(pr[i][j]==3||pr[i][j]==4)i--,j--;
    }
    while(!ss.empty())
    {
        cout<<ss.top()<<endl;
        ss.pop();
    }
    return 0;
}
