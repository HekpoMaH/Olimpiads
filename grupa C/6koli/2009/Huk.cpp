#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double ans=1e30;
int n,i,j;
double a[32768],b[32768];
double dist(double x1,double y1,double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
  cin>>n;
  for(i=0;i<n;i++)
  {
   cin>>a[i]>>b[i];
    for(j=0;j<i;j++)
       {
           ans=min(ans,dist(a[i],b[i],a[j],b[j]));
       }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(5)<<ans<<endl;
    return 0;
}
