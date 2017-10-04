/*
task: stamps
lang: c++
*/
#include<iostream>
#include<vector>
using namespace std;
int dp[5000+10];
int st[3000+10];
int main()
{
    int S,N;
    cin>>S>>N;
    for(int i=0; i<N; i++)
    {
            cin>>st[i];
    }
    for(int i=0; i<=S; i++)
    {
            dp[i]=9999999;
    }
    for(int i=0; i<N; i++)
    {
            for( int j=i; j<=S; j++)
            { 
                  if(j==st[i])dp[j]=1;
                 for( int z=0; z<N; z++)
                 {
                     
                   if(dp[j+st[i]]>dp[j]+1)dp[j+st[i]]=dp[j]+1;
                 }
            }
    }

    cout<<dp[S]<<endl;
    return 0;
}
