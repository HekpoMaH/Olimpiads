#include<iostream.h>
int main()
{
	 double a,b,c;
		 double x;
	 cout<<"vavedete a,b,c";
	 cin>>a;
	 cin>>b;
	 cin>>c;
	 if(c>=b)
	 {
	 x=(c-b)/a;
	 cout<<a<<"x+ "<<b<<"="<<c<<"        x="<<x<<"\n";
	 }
	 else
	 {
		 cout<<"ERROR b>c\n";
	 }
	 return 7;
} 