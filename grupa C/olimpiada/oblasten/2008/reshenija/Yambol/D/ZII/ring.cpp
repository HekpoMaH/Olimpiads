#include<iostream>
using namespace std;
int main()
{
	int N,K,Ki=0,A[101],i=0,br=0,fl=0;
	cin>>N>>K;
		A[K]=A[0];
	do
	{
		cin>>Ki;
		do
		{
			if (A[Ki]!=0)
				br=1;
			if (A[Ki]==0)
				{
					A[Ki+1]=0;
					A[Ki]=A[Ki+1];
				}
		}
		while(br=0);
		fl++;
	}
	while (fl!=N);
	fl=0;
	br=0;
	for (i=1;A[i]=A[N];i++)
		{
			if (i!=0)
				fl=A[i];
			if (A[i]==0)
				{
					br++;
				}
			if (N-br==1)
				cout<<fl;
		}
	return 0;
}
