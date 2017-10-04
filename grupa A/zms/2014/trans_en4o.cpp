#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
typedef long long Int;

Int Tree[1048576];
Int LEAFOFFSET=1;
vector<Int> trucks[21];

Int MAX(Int a,Int b)
{
	if (a>b)
	return a;
	else
	return b;
}

Int MIN(Int a,Int b)
{
	if (a<b)
	return a;
	else
	return b;
}

Int GetMAX(Int k)
{
	Int ind=k+LEAFOFFSET;
	Int MAXVAL=Tree[ind];
	
	while(ind>1)
	{
		if (ind%2==1)
		MAXVAL=MAX(MAXVAL,Tree[ind-1]);
		
		ind/=2;
	}
	
	return MAXVAL;
}

void MakeZero(Int k)
{
	Int ind=k+LEAFOFFSET;
	Tree[ind]=0;
	ind/=2;
	
	while(ind>0)
	{
		Tree[ind]=MAX(Tree[2*ind],Tree[2*ind+1]);
		ind/=2;
	}
	
	return;
}

int main()
{
	Int n,k;
	Int expected;
	Int i,j;
	Int sum=0;
	Int need;
	Int num;
	
	scanf("%lld %lld",&n,&k);
	
	while(LEAFOFFSET<n)
	LEAFOFFSET*=2;
	LEAFOFFSET--;
	
	expected=(n*(n+1))/2;
	
	if (expected%k!=0)
	{
		printf("NO\n");
		return 0;
	}
	
	expected/=k;
	
	for (i=1;i<=2*LEAFOFFSET+1;i++)
	{
		Tree[i]=0;
	}
	
	for (i=1;i<=n;i++)
	{
		Tree[i+LEAFOFFSET]=i;
	}
	for (i=LEAFOFFSET;i>=1;i--)
	{
		Tree[i]=MAX(Tree[2*i],Tree[2*i+1]);
	}
	
	for (i=1;i<=k;i++)
	{
		sum=0;
		
		while(sum<expected)
		{
			need=MIN(n,expected-sum);
			
			num=GetMAX(need);
			
			if (num==0)
			{
				printf("NO\n");
				return 0;
			}
			else
			{
				MakeZero(num);
			}
			
			sum+=num;
			trucks[i].push_back(num);
		}
	}
	
	for (i=1;i<=k;i++)
	{
		printf("%lld\n",(Int)trucks[i].size());
		for (j=0;j<(Int)trucks[i].size();j++)
		{
			if (j==0)
			printf("%lld",trucks[i][j]);
			else
			printf(" %lld",trucks[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
