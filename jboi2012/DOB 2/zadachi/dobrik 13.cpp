#include<iostream.h>
int main()
{
	int a,d,s,e,f,t;
	cout<<"vavedete chetiricifreno chislo";
	cin>>a;
	d=a/1000;
	
	s=a%1000;
		
	e=s%100;
	
	s=s/100;
	
	f=e%10;
	
	e=e/10;
	
	t=d+s+e+f;
	cout<<"sumata="<<t<<"\n";
	return 0;
}
