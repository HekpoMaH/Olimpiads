#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int n;
double siz(double xx1,double yy1,double xx2,double yy2)
{
  return (fabs(yy2+yy1)*fabs(xx1-xx2)/2);
}
int main()
{
  double x1,x2,y1,y2,s1=0,s2=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x1>>y1>>x2>>y2;
    if(fabs(y1+y2)==y1+y2)s1+=siz(x1,y1,x2,y2);
    if(fabs(y1+y2)==-(y1+y2))s2+=siz(x1,y1,x2,y2);
  }
  cout<<setiosflags(ios::fixed)<<setprecision(2)<<fabs(s1-s2)<<endl;
  return 0;
}
