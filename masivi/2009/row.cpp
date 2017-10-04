#include<iostream>
using namespace std;
int main()
{
	int n;
	long long int min=10000,a[1000],max=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<min)min=a[i];
		if(a[i]>max)max=a[i];
	}
	double s=0;
	s=(double)min/3+(double)max/3*2;
	int i=0,l=0 ;
	do
	{
		if(a[i]<=s){l++;}
		i++;
	}
	while(l==0);
	cout<<i<<endl;
	return 0;
}
