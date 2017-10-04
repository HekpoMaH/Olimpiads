#include<iostream.h>
int main()
{
	int a,b,c;
	cout<<"vavedete nomer na den ot godinata";
	cin>>a;
	b=a/7;
	b=b+1;
	c=a%7;
	if(c==1)
	{
		cout<<"sedmica "<<b<<" den ponedelnik";
	};
	if(c==2)
	{
		cout<<"sedmica "<<b<<" den vtornik";
	};
	if(c==3)
	{
		cout<<"sedmica "<<b<<" den sriada";
	};
	if(c==4)
	{
		cout<<"sedmica "<<b<<" den 4etvartak";
	};
	if(c==5)
	{
		cout<<"sedmica "<<b<<" den petak";
	};
	if(c==6)
	{
		cout<<"sedmica "<<b<<" den sabota";
	};
	if(c==0)
	{
		cout<<"sedmica "<<b<<" den nedelq";
	};
	cout<<"\n";
return 7;
}
