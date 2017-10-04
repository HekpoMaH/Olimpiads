#include<cstdio>
#include<iostream>
using namespace std;
int n, p;
double dp[512][512];
double b[512];
double s1[512], s2[512];
void make(int u, int v)
{

	int k;
	for(k=1;k<=u;k++)
	{
		if(!(dp[k-1][v-1]<0))
		{

			double avg=0,br=0;
			int i;
	//		for(i=k;i<=u;i++){avg+=b[i];br++;}
			avg=(double)(s1[u]-s1[k-1])/(double)(u-k+1);

			double dpt=0;
			//for(i=k;i<=u;i++)dpt+=(b[i]-avg)*(b[i]-avg);
         dpt=(s2[u]-s2[k-1])-2*avg*(s1[u]-s1[k-1])+(double)(u-k+1)*avg*avg;
         
			if(dp[k-1][v-1]+dpt<dp[u][v]||dp[u][v]<0)
			{
				dp[u][v]=dp[k-1][v-1]+dpt;
			}

		}

	}


}
int main()
{

	scanf("%d%d",&n,&p);

	double c;
	int i,j;
	for(i=0;i<512;i++)
	   for(j=0;j<512;j++)
	     dp[i][j]=-1;
	dp[0][0]=0.0;
	for(i=1;i<=n;i++)
	{
		double t;
		
		scanf("%lf",&t);
		s1[i]=s1[i-1]+t;
		s2[i]=s2[i-1]+t*t;
		b[i]=t;
		
		for(j=1;j<=p;j++)
		{
			make (i, j);
			
		}

	}

	printf("%.4lf\n", dp[n][p]);
	return 0;
}
