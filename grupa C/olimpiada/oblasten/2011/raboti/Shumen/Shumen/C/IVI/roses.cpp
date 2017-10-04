#include<iostream>
using namespace std;
int n,m,k,a[1024][1024],sum,msum,allsum;
void read()
{
  int i,j;
  cin>>m>>n>>k;
  for (i=0;i<m;i++)
  for (j=0;j<n;j++)
  cin>>a[i][j];
}
void solve()
{
  int i,j;
  for (i=0;i<m;i++)
  for (j=0;j<n;j++)
  allsum+=a[i][j];
  for (i=0;i<m;i++)
  for (j=0;j<n;j++)
  {
    sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
    if (sum>msum)
    msum=sum;
    sum=0;
  }
  cout<<allsum-msum<<endl;
}
int main()
{
 read();
 solve();
return 0;
}