#include<iostream>
using namespace std;
long long v[5000],i,j,s,k,a,x[5000],y;
int main()
{
	v[1]=v[2]=1;
	cin>>s>>k;
	for(i=3;i<=k+1&&s>=v[i-1];i++)v[i]=v[i-1]*2;
	//for(i=3;i<=k+1&&s>=v[i-1];i++)cout<<v[i]<<" "<<i<<endl;
	i--;
	while(v[i]<s)
	{
		i++;
		v[i]=2*v[i-1]-v[i-k-1];
	}
	while(s!=0)
	{
		while(v[i]>s)i--;
		y++;
		x[y]=v[i];
		s-=v[i];
	}
	if(y==1){y++; x[y]=0;}
	cout<<y<<endl;
	for(i=1;i<=y;i++)cout<<x[i]<<" ";
	cout<<endl;
	return 0;
}