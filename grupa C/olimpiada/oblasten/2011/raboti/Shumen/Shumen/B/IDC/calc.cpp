#include<iostream>
using namespace std;
int n,s;
int dp[1000004];
void read ()
{
     cin>>s;
     cin>>n;
}
void solve ()
{
     dp[0]=0;
     int i,best;
     for(i=1;i<=n;i++)dp[i]=1;
     for(i=n+1;i<=s;i++)
     {
                        best=120000;
                        for(int j=1;j<=n;j++)
                        {
                                if((dp[i-j]+1)<best)best=dp[i-j]+1;
                                if(j>1&&i%j==0)
                                {
                                               if((dp[i/j]+1)<best)best=dp[i/j]+1;
                                }
                        }
                        dp[i]=best;
     }
     cout<<dp[s]<<endl;
    // printf("%d\n",dp[s]);
}
int main ()
{

    read ();
    //for(int i=1;i<=60;i++)n=i;
    //s=t;
    solve ();
    
    return 0;
}
