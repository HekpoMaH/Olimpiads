#include <stdio.h>
double d[512];
double A[512][512];
double dp[512][512];
int main()
{
  int n,k,g;
  int i,j;
  scanf("%d %d",&n,&k);
  for(i = 0;i < n;i++)
  {
    scanf("%lf",&d[i]);
  }
  double Sum;
  double SumSQ;
  double pp;
  for(i = 0;i < n;i++)
  {
    Sum = 0;
    SumSQ = 0;
    for(j = i;j < n;j++)
    {
       Sum += d[j];   
       SumSQ += d[j]*d[j];  
       pp = (double)j-i+1;
       A[i][j] = SumSQ - Sum*Sum/pp;
     }
 }
  for(i = 0; i < n;i++)
  {
      dp[0][i] = A[0][i];
  }
  for(i = 1;i < k;i++)
  {
     for(j = i;j < n;j++)
     {
          dp[i][j] = dp[i-1][i-1] + A[i][j];
          for(g = i-1;g <= j;g++)         
          {
              if(dp[i][j] > (dp[i-1][g] + A[g+1][j]))
              {
                  dp[i][j] = dp[i-1][g] + A[g+1][j];
              }
          }
     }
  }
  printf("%.4lf",dp[k-1][n-1]);

  return 0;
}


//printf("i = %d,j = %d,g = %d ,dp[j][i] = %lf, dp[g][i-1] = %lf ,A[j+g][j] = %lf\n",i,j,g,dp[j][i],dp[j-g][i-1],A[j][j-g]);
