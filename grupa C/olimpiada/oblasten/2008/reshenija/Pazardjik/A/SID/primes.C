#include<stdio.h>
int A[100000];
unsigned long int count=0;

void make_primes(void);
void func(int n,int limit);

void main(void)
{
	int i=0;
	int a=2,b=0,n=0;

	make_primes();
	scanf("%d",&n);
	
	func(n,2);
	printf("%d",count);
}

void make_primes(void)
{
	int i=0,j=0;	

	for(i=2;i<50000;i++)
		for(j=2*i;j<50000;j=j+i)
			A[j]=1;
}

void func(int n,int limit)
{
	int a=limit,b=n-limit;
	
	while(!(a>b))
	{
		if(A[b]==0)
		{count++;func(b,a);}
		else func(b,a);
		do
		{
			a++;
		}while( (A[a]!=0)&&(a<n) );
		b=n-a;
		
	}
}