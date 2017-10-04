#include<iostream>
using namespace std;
int n,a[1005][1005],st[1005][1005],m[1005][1005];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=1;i<=n;i++)st[n][i]=a[n][i];
  for(int i=n-1;i>=1;i--)
  {
    for(int j=1;j<=i;j++)
    {
      if(st[i+1][j]>st[i+1][j+1])
      {
        st[i][j]=a[i][j]+st[i+1][j];
        m[i][j]=j;
      }
      else
      {
        st[i][j]=a[i][j]+st[i+1][j+1];
        m[i][j]=j+1;
      }
    }
  }
  cout<<st[1][1]<<endl;
  int c=1;
  cout<<1<<" "<<1<<endl;
  for(int i=1;i<n;i++)
  {
    c=m[i][c];
    cout<<i+1<<" "<<c<<endl;
  }
  return 0;
}
