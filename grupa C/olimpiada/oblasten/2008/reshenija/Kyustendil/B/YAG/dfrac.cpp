// dfrac.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{int a,b,k,p;unsigned __int64 c;unsigned __int64 e[20],d=0;
 cin>>a>>b;
 cin>>k>>p;
 c=a;
 e[0]=0;
 for(int i=1;i<(k+p);i++)
 {c=c%b;
  e[i]=(c*10)/b+e[i-1]*10;
  if(i>=k)d=(c*10)/b+d*10;
  c=(c*10)%b;
 }cout<<d;
	return 0;
}

