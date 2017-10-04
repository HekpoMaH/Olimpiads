#include<iostream>
using namespace std;

int z,n;
int a[3000];
int k=0;

int main()
{
	cin>>z>>n;
	int s=z;	
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int y,x;
	int r=5000;
	for(i=n-1;i>=0;i--)
	{
		for(int j=i;j>=0;j--)
		{
			
			do
			{
				s-=a[j];
				k++;
			}while(s-a[j]>=0);
	
			if(j==i) {y=s;x=k;}
		}
	
		if(k<r) r=k;
		s=y+a[i];
		k=x-1;
	}
		
	cout<<r<<endl;
	return 0;
}