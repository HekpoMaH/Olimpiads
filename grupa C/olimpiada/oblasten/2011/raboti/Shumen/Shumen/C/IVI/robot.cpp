#include<iostream>
using namespace std;
int m,n,k,o=1,r,a[128][128],sum;
int main()
{
  int i,j,x=1;
  cin>>m>>n>>r>>k;
  for (i=0;i<m;i++)
  for (j=0;j<n;j++)
  {
    a[i][j]=o;
    o++;
  }
  for (i=0;i<m;i++)
  for (j=0;j<n;j++)
  {
    if (a[i][j]==r)
    {
      while (x<=k)
      {
        sum+=a[i][j+(k-k+x)];
        sum+=a[i][j-(k-k+x)];
        sum+=a[i+(k-k+x)][j];
        sum+=a[i-(k-k+x)][j];
        x++;
      }
    }
  }
  cout<<sum<<endl;

return 0;
}