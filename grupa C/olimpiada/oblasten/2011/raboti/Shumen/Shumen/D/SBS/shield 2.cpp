#include<iostream>
using namespace std;
int main ()
{
  int a[100],b[100],sum1[100],minsum1=500,minsum2=500,minsum3=500,max=0,sum2[100],sum3[100],i,n;
  cin>>n;
  for (i=1; i<=n; i++)
  {
    cin>>a[i];
  }
  for (i=1; i<=n; i++)
  {
    cin>>b[i];
  }
  for (i=1; i<=n; i++)
  {
    sum1[i]=(a[i]+b[i]);
    if (sum1[i]<minsum1)
    minsum1=sum1[i];
  }
  for (i=1; i<=n; i++)
  {
    sum2[i]=(a[i]+b[n-i+1]);
    if (sum2[i]<minsum2)
    minsum2=sum2[i];
  }
  for (i=1; i<=n; i++)
  {
    sum3[i]=(a[n-i+1]+b[i]);
    if (sum3[i]<minsum3)
    minsum3=sum3[i];
  }
  if (minsum1>max)
  max=minsum1;
  if (minsum2>max)
  max=minsum2;
  if (minsum3>max)
  max=minsum3;
  cout<<max<<endl;
  return 0;
}