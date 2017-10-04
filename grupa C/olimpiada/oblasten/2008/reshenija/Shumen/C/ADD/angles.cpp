#include<cstdio>
#include<iostream>
using namespace std;
int n,k,a[1024][1024],b[1024][1024],c[1024][1024],m,mn1,mn2;
int main()
{
 int i,i2;
 scanf("%d%d",&n,&k);
 for(i=1;i<=n;i++)
  for(i2=1;i2<=n;i2++)scanf("%d",&a[i][i2]);
 for(i=1;i<=n;i++)
 {
  b[n][i]=a[n][i];
  c[i][n]=a[i][n];
 }
 for(i=n-1;i>0;i--)
  for(i2=n;i2>0;i2--)
  {
   b[i][i2]=b[i+1][i2]+a[i][i2];
   if(i<n-k)b[i][i2]-=a[i+k+1][i2];
  }
 
 
 for(i=n;i>0;i--)
  for(i2=n-1;i2>0;i2--)
  {
   c[i][i2]=c[i][i2+1]+a[i][i2];
   if(i2<n-k)c[i][i2]-=a[i][i2+k+1];
  }


 /*
 for(i=n-1;i>=n-k;i--)
  for(i2=n-k-1;i2>0;i2--)
  {
   b[i][i2]=b[i+1][i2]+a[i][i2]-b[i+k][i2];
   c[i][i2]=c[i][i2+1]+a[i][i2]-c[i][i2+k];
  }
 for(i=n-k-1;i>=>0;i--)
  for(i2=n-1;i2>0;i2--)
  {
   b[i][i2]=b[i+1][i2]+a[i][i2]-b[i+k][i2];
   c[i][i2]=c[i][i2+1]+a[i][i2]-c[i][i2+k];
  }
  
 cout<<endl;
 for(i=1;i<=n;i++)
 {
  for(i2=1;i2<n;i2++)
   cout<<b[i][i2]<<" ";
  cout<<b[i][i2]<<endl;
 }
 cout<<endl;
 for(i=1;i<=n;i++)
 {
  for(i2=1;i2<n;i2++)
   cout<<c[i][i2]<<" ";
  cout<<c[i][i2]<<endl;
 }
 cout<<endl;
 */
 
 
 for(i=1;i<=n;i++)
 {
  for(i2=1;i2<=n;i2++)
  {
   //cout<<b[i][i2]+c[i][i2]-a[i][i2]<<" ";
   if(b[i][i2]+c[i][i2]-a[i][i2]>m)
   {
    m=b[i][i2]+c[i][i2]-a[i][i2];
    mn1=i;
    mn2=i2;
   }
  }
  //cout<<endl;
 }
 cout<<mn1<<" "<<mn2<<endl;
 return 0;
}
