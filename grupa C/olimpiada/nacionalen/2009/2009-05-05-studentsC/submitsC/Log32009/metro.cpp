/*
TASK:metro
LANG:C++
*/
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int dp[1025][150];
int lev[1025];
int n;
int main()
{
    memset(dp,0x7F,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<=140;i++)
    dp[0][i]=0;
    for(int i=1;i<=n;i++)
    scanf("%d",&lev[i]);
    int token=0x7F8F8F8F;
    int mini=token;
    for(int j=1;j<=n;j++)
    for(int i=0;i<=120;i++)
    {
        token=min(dp[j-1][i+2],min(dp[j-1][i+1],min(dp[j-1][i],dp[j-1][max(0,i-1)])));
       // printf("the chosen one is - %d on pos %d %d",token,j,i);
      //  system("pause"); 
        if(i==lev[j]) token+=1;
        else if(i>lev[j]) token+=(i-lev[j])*7;
        else token+=(lev[j]-i)*(lev[j]-i);
        dp[j][i]=token;
        if(j==n) 
        if(token<mini) mini=token;
    }
    printf("%d\n",mini);
    return 0;
}
