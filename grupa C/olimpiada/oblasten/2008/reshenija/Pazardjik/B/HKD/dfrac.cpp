#include<iostream.h>
#include<stdlib.h>

int main()
{
	int a,b,k,p;
	cin>>a>>b>>k>>p;
	a*=10;
	char c[51];
	int z=0;
	for(int i=0;i<k+p;i++)
	{
		
		if(z>=50) z=0;
		c[z]=int(a/b)+48;
		a=a%b;
	}
	for(i=k;i<k+p;i++)
	{
		cout<<atoi(c);
	}
	return 0;
}