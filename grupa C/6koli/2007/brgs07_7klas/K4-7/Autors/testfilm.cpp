#include <cstdio>
using namespace std;
int main()
{
	int x,y,n,ans=0,p;
	scanf("%d %d %d",&x,&y,&n);
	if(x==y)
	{
		printf("0\n");
		return 0;
	}
	p=x*n;
	while(p/n>y)
	{
		//printf("%lf\n",(double)p/n);
		ans++;
		p++;
		n++;
	}
	//printf("%lf\n",double(p/n));
	printf("%d\n",ans);
	return 0;
}