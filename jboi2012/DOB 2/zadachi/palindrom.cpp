#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a;
	b=0;
	int d;
	d=a;
	while(d!=0)
	{
		c=d%10;
		b=b*10+c;
		d=d/10;
	}
	if(a==b)
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}
	system("pause");
	return 0;
}
