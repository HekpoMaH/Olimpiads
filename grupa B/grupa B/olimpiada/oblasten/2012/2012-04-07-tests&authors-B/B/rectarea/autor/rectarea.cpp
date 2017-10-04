#include<iostream>
#include <algorithm>
using namespace std;
struct trect
{
    int xmin,ymin,xmax,ymax;
};
   void readrect( trect &r)
   {
       int x1,y1,x2,y2;
       cin>>x1>>y1>>x2>>y2;
      r.xmin=min(x1,x2);
      r.xmax=max(x1,x2);
      r.ymin=min(y1,y2);
      r.ymax=max(y1,y2);
   }
   void kill(int *a,int &count)
   {
     int i, j=1;
      for (i=2; i<=count; i++)
       { if (a[i]!=a[i-1])
            j++;
            a[j]=a[i];
       }
      count=j;
   }

   bool belongs(int x, int y, trect r)
   {
     return ((r.xmin<=x)&&(x<r.xmax)&&(r.ymin<=y)&&(y<r.ymax));
   }

int main()
{int i,j,k,n;
 trect r[201];
   int x[404];
    int y[404];
  int xcount=0,ycount=0;
   bool painted;
   long long area;

  cin>>n;
  for(i=1;i<=n;i++)
      readrect(r[i]);
  for(i=1;i<=n;i++)
  {
      xcount++;
      x[xcount]=r[i].xmin;
      xcount++;
      x[xcount]=r[i].xmax;
      ycount++;
      y[ycount]=r[i].ymin;
      ycount++;
      y[ycount]=r[i].ymax;
  }

   sort(x+1,x+xcount+1);
   kill(x,xcount);
   sort(y+1,y+ycount+1);
   kill(y,ycount);
   
   area=0;
   for(i=1;i<=xcount;i++)
    for(j=1;j<=ycount;j++)
     {
       painted=false;
         for (k=1;k<=n;k++)
            if (belongs(x[i],y[j],r[k]))
               {painted=true;
               break;}
              // cout<<x[i]<<' '<<x[i+1]<<' '<<y[j]<<' '<<y[j+1]<<' '<<painted<<' '<<k<<endl;
         if (painted) area=area+(long long)(x[i+1]-x[i])*(y[j+1]-y[j]);
     }
   cout<<area<<endl;
}
