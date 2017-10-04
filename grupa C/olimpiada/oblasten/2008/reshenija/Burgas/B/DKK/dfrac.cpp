#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
	long long int a,b;
	cin>>a>>b;
	double x=1.0*a/b;
	long int k;
	int p;
	cin>>k>>p;
	for (int i=0;i<k-1;i++)
	 	x=x*10;
	 
	int brp=0; 
	x=x-floor(x);
	do { int f=x*10;
		cout<<f;
		x=x*10-f;
		brp++;
		}while(brp!=p);
	cout<<endl;
	
	return 0;
}
