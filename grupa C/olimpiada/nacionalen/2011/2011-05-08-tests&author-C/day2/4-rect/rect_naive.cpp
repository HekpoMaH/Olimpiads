#include<iostream>
#include<cmath>
using namespace std;

int m,n;
int x[5], y[5];

int ds(int i1, int i2)
{ return (x[i1]-x[i2])*(x[i1]-x[i2])+(y[i1]-y[i2])*(y[i1]-y[i2]);}

int s()
{
  return (2*n*m-y[1]*x[2]-(m-x[2])*y[3]-(n-y[3])*(m-x[4])-x[4]*(n-y[1]))/2;
}

int main()
{
  cin >> m >> n;
  
  int rmin=m*n, rmax=0;
  
  for(int i1=0;i1<=n;i1++)
  for(int i2=0;i2<=m;i2++)
  for(int i3=0;i3<=n;i3++)
  for(int i4=0;i4<=m;i4++)
  {

    x[1]=0;y[1]=i1;
    x[2]=i2;y[2]=0;
    x[3]=m;y[3]=i3;
    x[4]=i4;y[4]=n;
    
    int d1=ds(1,2);
    int d2=ds(2,3);
    int d3=ds(3,4);
    int d4=ds(4,1);
    int dd1=ds(1,3);
    int dd2=ds(2,4);
    

    if(d1==d3&&d2==d4&&dd1==dd2)

    {
//      cout << d1 << " " << d2 <<  " ";
//      cout << sqrt(d1) << " " << sqrt(d2) << " ";
//      cout << s() << "   ";
//      cout << sqrt(d1)*sqrt(d2) << endl;
      int ss=s();
      if(ss!=0)
      if(ss<rmin)rmin=ss;
      if(ss!=m*n)
      if(ss>rmax)rmax=ss;

    }
    
  }

 cout << rmin << ".0 " << rmax << ".0" << endl;

}
