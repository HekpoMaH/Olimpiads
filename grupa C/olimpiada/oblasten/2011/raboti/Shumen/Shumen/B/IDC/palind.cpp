#include<iostream>
#include<stack>
using namespace std;
int n,a[10004];
int pal[1024][1024];
stack<int> st;
void read ()
{
     cin>>n;
     for(int i=1;i<=n;i++)
     {
             cin>>a[i];
     }
}
int k[1028];
int dp[10000];
void solve ()
{
     int i,j,y,br;
     for(i=1;i<=n;i++)
     for(j=i+1;j<=n;j++)
     {
                        br=0;
                        for(y=0;y<=j-i;y++)
                        if(a[i+y]==a[j-y])br++;
                        else break;
                        if(br==(j-i+1)){pal[i][j]=1;}
     }
     dp[1]=1;
     k[1]=0;
    // cout<<pal[3][4]<<endl;
     for(i=2;i<=n;i++)
     {
                      dp[i]=dp[i-1]+1;
                      k[i]=i-1;
                      for(j=i-1;j>0;j--)
                      {
                               if(pal[j][i]==1)
                               {
                                               if(dp[j-1]+1<dp[i]){dp[i]=dp[j-1]+1;k[i]=j-1;}
                               }         
                      }
                     // cout<<i<<' '<<dp[i]<<' '<<k[i]<<endl;
     }
     int t=k[n],ans=0;
     while(t!=0)
     {
                st.push(t);
                t=k[t];
                ans++;
     }
     cout<<dp[n]<<endl;
     if(ans>0)
     {cout<<st.top();
     st.pop();
     while(!st.empty())
     {
                       cout<<' '<<st.top();
                       st.pop();
     }
     cout<<endl;
     }
}
int main ()
{
    read();
    solve ();
    return 0;
}
