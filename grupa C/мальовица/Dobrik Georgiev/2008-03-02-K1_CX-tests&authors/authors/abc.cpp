 /*
  P. Hristova
  Kontrolno Shkola Haskovo 2009
  */  
#include <iostream>
using namespace std;

int nod(int a, int b)
{
 while (a!=b)
  if (a>b) a-=b;
    else b-=a;
 return a;
}
int toch(int x1, int y1, int x2, int y2)
{
    int m,n,t;
  m= abs(x1-x2); n=abs(y1-y2);
  if (n==m) t=m;
  else if (n==0) t=m;
     else if(m==0) t=n;
       else  t=nod(m,n);        
  return t;  
}    
int main()
{
  int xa,xb,xc,ya,yb,yc,m,n,k=0,t;
  cin >>xa>>ya>>xb>>yb>>xc>>yc;
  k +=toch(xa,ya,xb,yb);
  k +=toch(xa, ya, xc, yc);
  k +=toch(xb, yb,xc,yc);
  cout <<k<<endl;
}
