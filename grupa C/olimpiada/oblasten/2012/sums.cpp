#include<iostream>
using namespace std;
bool dp[10003];
int br,n,a,b,x[102];
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        //dp[x[i]]=true;
    }
    dp[0]=true;
    for(int k=1;k<=n;k++)
    for(int i=10000;i>=0;i--)
    {
        if(dp[i]==1)dp[i+x[k]]=1;
    }
    for(int i=a;i<=b;i++)
    {
        if(dp[i]==1)br++;
    }
    cout<<br<<endl;
    return 0;
}
