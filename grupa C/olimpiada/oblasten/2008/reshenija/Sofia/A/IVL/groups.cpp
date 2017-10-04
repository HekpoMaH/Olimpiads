#include <cstdio>

using namespace std;

int n,p;
double mas[512];
double d[512][512];
double ans[512][512];
int resh[512];

void dist()
{
	double sum=0,sa,raz;
	for(int i=0;i<n;i++)
	{
		sum=0;raz=0;
		for(int j=0;j<n-p+1;j++)
		{
			if(i+j>=n) break;
			sum+=mas[i+j];
			sa= sum/(j+1.0);
			raz=0;
			for(int k=0;k<=j;k++)
			{
				raz+=(sa-mas[i+k])*(sa-mas[i+k]);
			}
			d[i][i+j]=raz;
		}
	}
}

void solve()
{
	double min;
	int g=n-p+1;
	for(int i=0;i<g;i++) ans[1][i]=d[0][i];
	g++;
	for(int i=2;i<=p;i++)
	{
		for(int j=i-1;j<g;j++)
		{
			min=99999999;
			for(int k=0;k<=j-(i-1);k++)
			{
				if(min>ans[i-1][j-k-1]+d[j-k][j]) min=ans[i-1][j-k-1]+d[j-k][j];
			}
			ans[i][j]=min;
		}
		g++;
	}
}

int main()
{
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++)
		scanf("%lf",&mas[i]);
	dist();
	solve();
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-p+1;j++)
		{
			if(i+j>=n) break;
			printf("distance %d %d = %lf",i,i+j,d[i][i+j]);
		}
	}*/
	printf("%.4lf\n",ans[p][n-1]);
	return 0;
}
