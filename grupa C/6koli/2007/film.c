#include <iostream>
using namespace std;
int bin_search(int l, int n, int sum, int y)
{
	int f=1,ans=0;
	while(f<=l)
	{
		ans=(l+f)/2;
		if(((double)(ans+sum)/(n+ans))>=y && ((double)(ans+sum)/(n+ans))<(y+1) )break;
		if(((double)(ans+sum)/(n+ans))>y+1)f=ans+1;
		else l=ans-1;
	}
	if((double)(ans+sum)/(n+ans)>=y+1)
	{
		while((double)(ans+sum)/(n+ans)>=(y+1))ans++;
		return ans;
	}
	while((double)(ans+sum)/(n+ans)<(y+1))ans--;
	return ans+1;
}
int main()
{
	int x,y,n,maxans,sum=0;
	cin>>x>>y>>n;
	if(x==y)
	{
		cout<<0<<endl;
		return 0;
	}
	sum=x*n;
	if(y==1)maxans=(x*n)-(y*n);
	else maxans=((x*n)-(y*n))/(y-1);
	cout<<bin_search(maxans,n,sum,y)<<endl;
	return 0;
}
