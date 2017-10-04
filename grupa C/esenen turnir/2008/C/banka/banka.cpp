#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;
int a[1024],koeficienti[1024],n,br,k,j,m;
int fac[13]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int b[1024],pointer;
void gen_perm()
{
	int i,p=0,cn=0;
	for(i=0;i<j;i++)
	{
		while(cn!=koeficienti[i])
		{
			if(a[p]>=0)cn++;
			p++;
		}
	//	printf("%d ",a[p-1]);
		b[pointer++]=a[p-1];
		a[p-1]=-1;
		p=0;
		cn=0;
	}
	//printf("\n");
}
 int main()
{
	int i,f,os,ans;
	scanf("%d %d %d",&n,&k,&m);
	for(i=0;i<n;i++)a[i]=i+1;
	ans=k;
	ans--;f=n-1;
	while(f)
	{
		koeficienti[j++]=(ans/fac[f])+1;
		//cout<<"ans="<<ans<<" fac["<<f<<"]="<<fac[f]<<endl;
		ans%=fac[f];
		f--;
	}
	for(int i=0;i<j;i++)cout<<koeficienti[i]<<" ";
	cout<<endl;
	koeficienti[j++]=1;
	gen_perm();
	for(j=k;j<=m;j++)
	{
		for(i=0;i<pointer-1;i++)printf("%d ",b[i]);
		printf("%d\n",b[i]);
		next_permutation(b,b+pointer);
	}
	return 0;
}
