#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,k,a,b,c,d;
	double sum=0;
	scanf("%d%d",&n,&k);
	n--;
	scanf("%d%d",&a,&b);
	while(n--)
	{
		scanf("%d%d",&c,&d);
		sum+=sqrt((c-a)*(c-a)+(d-b)*(d-b));
		
		a=c;b=d;
	}
	sum=sum*k/50;
	printf("%.9lf\n",sum);
	return 0;
}