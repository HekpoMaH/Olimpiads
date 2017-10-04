#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    unsigned long long int a,b,k,p,c,q=1;
    cin>>a>>b>>k>>p;
    a*=10;
    p+=k;
    while(q!=p)
    {
	   if(a<b&&a!=0){a*=10;if(k<=18)cout<<"0";q++;}
	   if(a>=b&&a!=0)
	   {    c=a/b;
		if(q>=k)cout<<c;
		a=a-(c*b);
		a*=10;
		q++;
	   }
	   else
	   if(a==0){cout<<"0";q++;}
	   else ;
    }
    cout<<endl;
//system("pause");
return 0;
}
