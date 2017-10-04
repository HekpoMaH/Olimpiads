#include<iostream>
using namespace std;
int main()
{
	int s,n,m;

	do{cin>>s;} while(s<=0 || s>=5000);
	do{cin>>n;} while(s<=0 || s>=3000);
	
	int st[n];
	
	for(int i=0;i<n;i++)
	{
	cin>>st[i];
	}
	
	for(int i=1;i<n;i++)
	for(int j=0;j<n-1;j++)
	{
	if(st[j+1]>st[j]) {
					m=st[j+1];
					st[j+1]=st[j];
					st[j]=m;
					}
	}
	
	int o=s;
	int k=0;
	int br=0;
	while(o!=0)
	{
	if(o-st[k]>=0)
	{
	o=o-st[k];
	br++;
	}
	else k++;
	}
	
	cout<<br;
return 0;
}
