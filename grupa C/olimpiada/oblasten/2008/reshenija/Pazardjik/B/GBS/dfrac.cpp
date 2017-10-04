#include<iostream>
using namespace std;
int main()
{
	int a,b,k,p,ost,l;
	cin>>a>>b>>k>>p;
	int i;
	a=a*10;
	char j[80];
	i=0;
	while(i<k+p)
	{
		l=a/b;
		ost =  a%b;
		//cout<<ost<<"\n";
		j[i]=l+48;
        //cout<<j[i];
		i++;
		if(ost%b == ost) a = ost*10;
	}
	for(i=k; i<=k+p; i++)
		cout<<j[i];
	return 0;
}