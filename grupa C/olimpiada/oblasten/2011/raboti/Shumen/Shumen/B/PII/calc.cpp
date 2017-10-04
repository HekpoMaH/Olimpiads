#include<iostream>
using namespace std;
int n;
int calc(int x)
{
	int i;
	i=n-1;
	while(i>=2)
	{
		if(x%i==0&&x/i>=n){x/=i;break;}
		i--;
	}
	return x;
}
int main()
{
	int s,i,br=1;
	cin>>s>>n;
	if(n==1){cout<<s<<endl;return 0;}
	while(1)
	{
		if(s==n)break;
		if(s-n<=n){br++;break;}
		if(s/n<n)
		{
			if(calc(s)==n){br++;break;}
			if(s==calc(s))
			{
				if(s-2*n<=n){br+=2;break;}
			}
			else {br+=2;break;}
		}
		if(s%n==0){s/=n;br++;}
		else
		{
			for(int j=1;j<=n;j++)
			if((s-j)%n==0){s-=j;s/=n;br+=2;break;}
		}
	}
	cout<<br<<endl;
	return 0;
}
