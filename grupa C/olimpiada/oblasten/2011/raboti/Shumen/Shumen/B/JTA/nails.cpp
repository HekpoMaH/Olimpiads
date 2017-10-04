#include <iostream>
using namespace std;

struct nail
{
     int x1;
     int x2;
     int y1;
     int y2;
};

nail a[1024];
int n;
void read()
{
     int i=1;
     int p1,p2,p3,p4;
     while(cin>>p1>>p2>>p3>>p4)
     {
          if(p1<p3)
          {
               a[i].x1=p1;
               a[i].y1=p2;
               a[i].x2=p3;
               a[i].y2=p4;
          }
          if(p1>p3)
          {
               a[i].x1=p3;
               a[i].y1=p4;
               a[i].x2=p1;
               a[i].y2=p2;
          }
          if(p1==p3)
          {
               if(p2>p4)
               {
               a[i].x1=p3;
               a[i].y1=p4;
               a[i].x2=p1;
               a[i].y2=p2;
               }
               if(p2<p4)
               {
               a[i].x1=p1;
               a[i].y1=p2;
               a[i].x2=p3;
               a[i].y2=p4;
               }

          }
          i++;
     }
     n=i-1;
}



int main()
{

     int i;
     read();
     cout<<n/2<<endl;
     return 0;
     }


