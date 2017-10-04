#include <iostream>
#include <ctime>

using namespace std;

bool pr[150000];
int p[150000],top=0;
int n;
int sum[150000];


int main()
{
	scanf("%d",&n);
	memset(pr,1,sizeof(pr));
//	for(int i=0;i<=n;i++)
//		cout<<i<<" "<<pr[i]<<"\n";
	pr[0]=pr[1]=0;
	int i;
	for(i=2;i*i<=2*n;i++)
		if(pr[i])
		{
			p[top++]=i;
			for(long long j=i*i;j<=2*n;j+=i)
				pr[j]=0;
		}
	for(;i<=n;i++)
		if(pr[i])
			p[top++]=i;
	for(;!pr[i];i++);
	int P=i;
//	cout<<top<<"\n";
	memset(sum,0,sizeof(sum));
	sum[0]=1;
	for(int i=0;i<top;i++)
		for(int j=p[i];j<=n;j++)
//			sum[j]+=sum[j-p[i]]; 
			sum[j]=(sum[j]+sum[j-p[i]])%P;
	

			
//	for(int i=0;i<=n;i++)
//		cout<<i<<" "<<sum[i]-pr[i]<<"\t";
//	cout<<sum[n]-pr[n]<<"\n";
//	cout<<P<<"\n";
	
	int res=sum[n]-pr[n];
	res+=P;
	res%=P;
//	cout<<sum[n]<<"\n";
//	cout<<res<<"\n";
	printf("%d\n",res);
//	printf("%f\n",clock()/(double)CLOCKS_PER_SEC);
	return 0;
}
