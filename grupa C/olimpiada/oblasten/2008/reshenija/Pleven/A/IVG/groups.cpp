#include <iostream>
#include <ctime>

#define inf 1e12

using namespace std;

int n,g;
double v[505],d[505][505],sum,di;

double a[505][505],NOT_SET;
double dp(int num,int last)
{
	double &ret=a[num][last];
	if(ret!=NOT_SET)
		return ret;
	if(last<0)
		return ret=num?inf:0;
	if(!num)
		return ret=inf;
	ret=inf;
	for(int i=0;i<=last;i++)
		ret=min(ret,dp(num-1,i-1) + d[i][last]);
	return ret;
}

int main()
{
	scanf("%d %d",&n,&g);
	for(int i=0;i<n;i++)
		scanf("%lf",&v[i]);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			sum=0;
			for(int k=i;k<=j;k++)
				sum+=v[k];
			double m=sum/double(j-i+1);
			di=0;
			for(int k=i;k<=j;k++)
				di+=(v[k]-m)*(v[k]-m);
			d[i][j]=di;
//			cout<<i<<" "<<j<<" "<<di<<"\n";
		}
	memset(a,-2,sizeof(a));
	NOT_SET=a[0][0];
//	cout<<NOT_SET<<"\n";
	printf("%.4lf\n",dp(g,n-1));
//	cout<<dp(g,n-1)<<"\n";
/*	for(int i=0;i<=g;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	} */
	return 0;
}
