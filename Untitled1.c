//Task:fractions
//Author T.Teodosiev
#include <iostream>
using namespace std;
void nesakr(long long a,long long b,long  long &c,long long &d)
 {long long p=a,q=b,r;
	   while (0!=b)
	   {r=a%b;a=b;b=r;}

	c=p/a;
	d=q/a;
  }
 int  main()
   {
    long long a=1,b=1,n,k=0;
    cin>>n;
      for (int d=2;d<=n;d++)
            {nesakr(a*d+b,d*b,a,b);k=k+a/b;a=a%b;}
      cout<<k<<' '<<a<<' '<<b<<endl;

    }

