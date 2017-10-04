#include<iostream>
#include<string>
#include<ctime>
#include<set>
#include<algorithm>
using namespace std;
int k;
string s;
string good;
int bad[1555][1555];
int dp[1555],br;
set<char> st;
int main()
{
    cin>>s;
    cin>>good;
    cin>>k;
    int n=s.size();
    for(int i=1;i<=n;i++){
        if(good[s[i]-'a']==0)dp[i]=dp[i-1]+1;else dp[i]=dp[i-1];}
    int l=0,r=1;
    while(l<n)
    {
        cout<<l<<" "<<r<<endl;
        if(r==n-1)l++;
        if(dp[r]-dp[l]<=k&&r<n-1)bad[l][r]=r-l+1,r++;
        else bad[l][r]=r-l+1,l++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(dp[j]-dp[i]<=k)br+=bad[i][j];
        }
    }
    cout<<br<<endl;
}
