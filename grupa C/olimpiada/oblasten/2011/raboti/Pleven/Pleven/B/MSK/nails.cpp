#include<iostream>
#include<cmath>
using namespace std;
int xx1,xx2,yy1,yy2,n,i,j,br,fl1,fl2,b[1024];
pair<pair<int, int>, pair<int, int> > q, a[1024];
int main()
{
 while(cin>>xx1>>yy1>>xx2>>yy2)
 {
  i++;
  a[i]=make_pair(make_pair(xx1,yy1),make_pair(xx2,yy2));

 }
 a[0]=a[i];
 a[i]=q;
 n=i-1;
 b[0]=1;
 for(i=1;i<=n;i++)
  if(b[i]!=1)
  {
   for(j=0;j<i;j++)
   {
    if(b[j]==1)
    {
     int x11=a[j].first.first;
     int y11=a[j].first.second;
     int x12=a[j].second.first;
     int y12=a[j].second.second;
     int a1=y11-y12;
     int b1=x12-x11;
     int c1=x11*y12-x12*y11;
     int d1=sqrt((x11-x12)*(x11-x12)+(y11-y12)*(y11-y12));
     int x21=a[i].first.first;
     int y21=a[i].first.second;
     int x22=a[i].second.first;
     int y22=a[i].second.second;
     int a2=y21-y22;
     int b2=x22-x21;
     int c2=x21*y22-x22*y21;
     int d2=sqrt((x21-x22)*(x21-x22)+(y21-y22)*(y21-y22));
     if(d2<d1 || (d1==d2 &&(min(x11,x12)<min(x21,x22))))
     {
      swap(x11,x21);
      swap(x12,x22);
      swap(y11,y21);
      swap(y12,y22);
      swap(a1,a2);
      swap(b1,b2);
      swap(c1,c2);
      swap(d1,d2);
     }
     if(a2!=0)
     {
      int z1=-(c2+b2*y11)/a2;
      int z2=-(c2+b2*y12)/a2;
      if(z1<x11) fl1=-1; else fl1=1;
      if(z2<x12) fl2=-1; else fl2=1;
      if(fl1+fl2==0 || z1==x11 || z2==x12)
      {
       b[i]=1; br++;
       break;
      }
     }
    }
   }
  }
 cout<<br<<endl;
 return 0;
}
/*
5 2 8 2
3 4 3 1
7 1 6 4
3 3 0 3
6 3 1 1
*/
