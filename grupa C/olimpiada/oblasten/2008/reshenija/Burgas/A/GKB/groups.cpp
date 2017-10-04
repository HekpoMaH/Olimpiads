#include <iostream>
#include <time.h>
using namespace std;
double sum[600];
double dp[600][600];
double precmp[600][600];
double el[600];
int N,P;
int main()
{
	int i,j;
		scanf("%d %d",&N,&P);
				for(i=1;i<=N;i++)
					{
						scanf("%lf",&el[i]);
					//	cout<<el[i]<<endl;
						sum[i]=sum[i-1]+el[i];
					}
			//	cout<<N<<" "<<P<<endl;
				for(i=0;i<=N;i++)
					{
						for(j=0;j<=P;j++)
							{
								dp[i][j]=99999999999.0;
							}
					}	
					//cout<<dp[N][P]<<endl;
				//	printf("%lf\n",dp[N][P]);
			int k;		
				for(i=1;i<=N;++i)
					{
						//j=500;
						for(j=i;j<=N;++j)
						{
							
							double t=sum[j]-sum[i-1];
							t/=double((j-(i-1)));
							for(k=i;k<=j;k++)
								{
									precmp[i][j]+=(el[k]-t)*(el[k]-t);
								}
							//cerr<<precmp[i][j]<<" ";
						//	printf("%lf\n",precmp[i][j]);
						}
						//cerr<<endl;
					}
			/*for(i=1;i<=N;i++)
			{
				for(j=1;j<=N;j++)
					cout<<precmp[i][j]<<" ";
			cout<<endl;
			}	*/
			for(i=1;i<=N;i++)
				dp[i][1]=precmp[1][i];
			dp[1][1]=0.0;
			for(i=2;i<=N;i++)
				{
					for(j=1;j<=P;j++)
						{
							for(k=1;k<i;k++)
								dp[i][j]=min(dp[i][j],dp[k][j-1]+precmp[k+1][i]);
								//if(dp[i][j]>dp[k][j-1]+precmp[k+1][i])
								//	dp[i][j]=dp[k][j-1]+precmp[k+1][i];
						}
				}	
			//	cout<<precmp[1][125]<<endl;
			//	cout<<precmp[126][250]<<endl;
			printf("%.4lf\n",dp[N][P]);	
			//cout<<dp[N][P]<<endl;
			//printf("%.4lf\n",double(clock())/CLOCKS_PER_SEC);
				return 0;
}
