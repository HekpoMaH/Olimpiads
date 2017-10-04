#include<stdio.h>
#include<cmath>
#include<iostream>

using namespace std;

   int dp[65536];
   int vec[6000],vn;
   int J;
   
bool issimple(int x)
{
   int j;
   for(j=0;j<vn && vec[j]*vec[j]<=x;j++)
   if(x%vec[j]==0)return false;
return true;
}

int main()
{
    int i,n,j;
    scanf("%d",&n);
  
    for(i=2;i<n;i++)
    if(issimple(i))vec[vn++]=i;
    
    for(i=n+1;1;i++)
    if(issimple(i))break;
    
    
    J=i;
    
    dp[0]=1;
    
    for(i=0;i<vn;i++)
    for(j=0;j+vec[i]<=n;j++)
    {
     dp[vec[i]+j]+=dp[j];
     if(dp[vec[i]+j]>J)dp[vec[i]+j]-=J;
    }
    
    printf("%d\n",dp[n]);
    
return 0;
}
