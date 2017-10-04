#include<stdio.h>
#include<vector>
using namespace std;
int n;int p;double num[512];
double dp[512][512];
void go(int i,int j)
{ int g;
for(g=1;g<=i;g++)
 if(dp[g-1][j-1]>=0)
 { int tmp;double d=0;
   for(tmp=g;tmp<=i;tmp++)
    d+=num[tmp];
    d/=double(i-g+1);
    double t=0;
    for(tmp=g;tmp<=i;tmp++)
     t+=(num[tmp]-d)*(num[tmp]-d);
     if((dp[g-1][j-1]+t<dp[i][j])||dp[i][j]<0)
     dp[i][j]=dp[g-1][j-1]+t;
}
}
int main()
{ scanf("%d%d",&n,&p);
int i,j;
for(i=0;i<=n;i++)
 for(j=0;j<=p;j++)
  dp[i][j]=-1;
 dp[0][0]=0;
for(i=1;i<=n;i++)
  scanf("%lf",&num[i]);
for(i=1;i<=n;i++)
 for(j=1;j<=p;j++)
  go(i,j);
printf("%.4lf\n",dp[n][p]);
return 0;
}
