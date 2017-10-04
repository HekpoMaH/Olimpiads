#include<iostream>
#include<cstdio>
using namespace std;
long m,n,br,dp[10001][2],a[10001];
bool used[8001][8001];
int main()
 {
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
   for(int i=1;i<=n;i++)
   {
     int l=i,r=i;
     while(a[l]==a[r]&&l>0&&r<=n)
     {
       used[l][r]=1;
       l--;r++;
     }
     if(i!=1&&a[i]==a[i-1])
     {
       l=i-1;r=i;
       while(a[l]==a[r]&&l>0&&r<=n)
       {
          used[l][r]=1;
          l--;r++;
       }
     }
   }
   dp[1][0]=1;
   for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
    {
      int t;
      if(n>5000) {if(a[i-j+1]==a[i]) used[i-j+1][i%2]=used[i-j+2][(i-1)%2];}
      else t=used[i-j+1][i];
      if(used[i-j+1][i]==1)
      {
        if(dp[i][0]==0||dp[i-j][0]+1<dp[i][0])
         {dp[i][0]=dp[i-j][0]+1;dp[i][1]=i-j;}
      }
    }
   cout<<dp[n][0]<<endl;
   if(dp[n][0]!=1)
   {int i=n;
    for(int j=dp[n][0]-1;j>=1;j--)
    {
      i=dp[i][1];
      a[j]=i;
    }
    cout<<a[1];
    for(int i=2;i<dp[n][0];i++)
    cout<<" "<<a[i];
    cout<<endl;
   }
   return 0;
 }
