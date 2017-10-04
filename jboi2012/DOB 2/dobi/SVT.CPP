#include<iostream.h>
int main()
{
	double v,s,t;
	int a;
	
	cout<<"1.tarsim vreme\n"<<"2.tarsim skorost\n"<<"3.tarsim pat\n";
	cin>>a;
	if(a==1)
	{
		cout<<"vavedete pata S=";
		cin>>s;
		cout<<"vavedete skorosta V=";
		cin>>v;
		t=s/v;
	}
	if(a==2)
	{
		cout<<"vavedete pata S=";
		cin>>s;
		cout<<"vavedete vreme T=";
		cin>>t;
		v=s/t;
	}
	if(a==3)
	{
		cout<<"vavedete vreme T=";
		cin>>t;
		cout<<"vavedete skorosta V=";
		cin>>v;
		s=v*t;
	}
	cout<<"s="<<s<<"km\nv="<<v<<"km/h\nt="<<t<<"h";
	return 7;
}