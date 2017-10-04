#include <iostream>
#include <cmath>
#include <string>

using namespace std;
long long int b,k,p;
double a,xxx,x;
double d;
int main()
{
    cin >> a >> b >> k >> p;
	long long int des,xx,y,i;
    des=1;
    for (i=1; i<=25; i++)
     des*=10;
	d=a/b;
//	cout << d << endl;
	x=trunc(a)-trunc(d)*b;
	d-=trunc(d);
	d*=10;
	for (i=16; i<=k; i+=5)
	{ 
	 //x=x-trunc(d);
	 //d-=trunc(d);
	 d*=des;
	 d+=0.000000000001;
	 y=trunc(d);
	 d-=0.000000000001;
	 xx=y*b;
	 while (x<xx)
	  x*=10;
	 x-=xx;
	 while (x<b)
	 	 x*=10;
	 d=x/b;
	} 
	i-=15;
	for (; i<k; i+=1)
	{
	//	d*=10;
	 d+=0.000000000001;
	 y=trunc(d);
	 d-=0.000000000001;
	 xx=y*b;
	 while (x<xx)
	  x*=10;
	 x-=xx;
	 while (x<b)
	 	 x*=10;
	 d=x/b;
	 //	cout << i << ' ' << d << endl;
	 	//cout << xxx << endl;
	//	d+=0.0000000001;
	}
//	d-=trunc(d);
//	d*=10;
//	cout << d << endl;
	string s="";
//	d+=0.0000000001;
//	x=xxx;
//	d-=0.0000000001;
	//cout << d << endl;
	for (i=1; i<=p; i++)
	{
	//	d*=10;
	 d+=0.000000000001;
	 y=trunc(d);
	// cout << x << '@' << y << endl;
	 d-=0.000000000001;
	 xx=y*b;
	 while (x<xx)
	  x*=10;
	 x-=xx;
	 if (x>0)
	 {
	 while (x<b)
	 	 x*=10;
	 }
	 d=x/b;
	// 	cout << i << ' ' << d << endl;
	// 	d+=0.000000000001;
	// y=trunc(d);
	// d-=0.000000000001;
		s=s+char(y+'0');
	}
	cout << s << "\n";
	return 0;
} 
		
		
