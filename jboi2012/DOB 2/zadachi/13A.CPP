#include<iostream.h>
int main()
{
	int a,b,c,d,e,s;
	cout<<"vavedete edno tricifreno chislo";
	cin>>a;
	b=a/100;
	c=a%100;
	d=c%10;
	e=c/10;
	s=100*d+10*e+b;
	cout<<"chisloto e="<<s<<"\n";
	return 0;
}
