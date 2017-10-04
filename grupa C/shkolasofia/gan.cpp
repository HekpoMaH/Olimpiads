#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
long long n,pol[55],br,br2,t;
double r[500],p[500],q[500],ans[500];
int main()
{
  cin>>n;
  for(int i=0;i<=n;i++)cin>>pol[i];
  for(int i=1;i<=abs(pol[n]);i++)
  {
    if(pol[n-1]%i==0)
    {
      p[br]=i;
      br++;
      p[br]=-i;br++;
    }
  }
  for(int i=1;i<=abs(pol[0]);i++)
  {
    if(pol[0]%i==0)
    {
      q[br2]=i;
      br2++;
      q[br2]=-i;br2++;
    }
  }
  t=0;
  for(int i=0;i<br;i++)for(int j=0;j<br2;j++)
  {
    r[t]=(double)p[i]/q[j];
    //cout<<r[t]<<endl;
    t++;
  }
  int x=t-1,j;
  //for(int i=0;i<x;i++)cout<<r[i]<<" ";
  for(int i=0;i<x-1;i++)
  {
    j=i+1;
    while(j<=x-1)
    {
      if(r[i]==r[j])
      {
        for(int l=j;l<x;l++)r[l]=r[l+1];
        x--;
      }
      else j++;
    }
  }
  //for(int i=0;i<x;i++)cout<<r[i]<<" ";
  t=0;
  //cout<<x<<endl;
  double pp;
  for(int i=0;i<x;i++)
  {
    pp=(double)0;
    for(int l=0;l<=n;l++)pp=pp*r[i]+(double)pol[l];
    //cout<<pp<<endl;
    if(fabs(pp)<.00000001){ans[t]=r[i];cout<<setiosflags(ios::fixed)<<setprecision(5)<<ans[t]<<" ";t++;}
  }
  cout<<endl;
  return 0;
}
