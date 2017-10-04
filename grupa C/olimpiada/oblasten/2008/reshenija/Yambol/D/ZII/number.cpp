#include<iostream>
#include<math>
using namespace std;
int main()
{
	int a,b,a2b,ab2,br,pom;
	cin>>a>>b>>a2b>>ab2;
	if (a!=0 && b!=0 && a2b==0 && ab2!=0)
		a2b=a*a*b;
	if (a!=0 && b!=0 && a2b!=0 && ab2==0)
		ab2=a*b*b;
	if (a==0 && a2b==0 && b!=0 && ab2!=0)
			{
				a=ab2/(b*b);
				a2b=a*a*b;
			}
	if (b==0 && a2b!=0 && a!=0 && ab2==0)
	{
		b=(a2b/a)/a;
		ab2=a*b*b;
	}
	if (b==0 && a!=0 && a2b!=0 && ab2!=0)
	{
		b=(ab2/a)/a;
	}
	if (b!=0 && a==0 && a2b!=0 && ab2!=0)
		a=(ab2/b)/b;
	if (b==0  && a==0 && a2b==0 && ab2!=0)
	{
			a=1;
			b=1;
		do
		{
			if (a*b*b!=ab2)
				b++;
			if (b*b*a>ab2)
				b=1;
				a++;
			a2b=a*a*b;
		}
		while(a*b*b!=ab2);
	}
	if (b==0  && a==0 && a2b!=0 && ab2==0)
	{
			a=1;
			b=1;
		do
		{
			if (b*b*a!=a2b)
				a++;
			if (b*a*a>a2b)
				a=1;
				b++;
			a2b=a*a*b;
		}
		while(a*a*b!=a2b);
	}
	cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2;
	return 0;
}
