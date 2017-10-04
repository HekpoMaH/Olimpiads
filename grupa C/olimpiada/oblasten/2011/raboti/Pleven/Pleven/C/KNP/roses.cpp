#include<iostream>
using namespace std;
long s,n,i,j,l,a[1001][1001],b[1001],j1,max1=-100000,max2,m,k,sum,sum1,o,max3;
int main()
{
cin>>m>>n>>k;
for(i=1;i<=m;i++)
{
  sum=0;
for(j=1;j<=n;j++)
{
cin>>o;
sum+=o;
a[i][j]=sum;sum1+=o;
}
}
for(i=1;i<=m;i++)
 for(j=1;j<=n-k+1;j++)
 {
  if(a[i][j+k-1]-a[i][j-1]>max1)
  {
  max1=a[i][j+k-1]-a[i][j-1];
  max2=a[i+1][j+k-1]-a[i+1][j-1];
  max3=a[i-1][j+k-1]=a[i-1][j-1];
  b[l]=max1+max2;
  b[l+1]=max1+max3;
  max2=0;max3=0;
  l+=2;
  }
 }
 sort(b,b+l);
 cout<<sum1-b[l-1]<<endl;
return 0;
}
/*
3 4 2
1 1 1 2
2 3 4 1
2 1 9 2
*/