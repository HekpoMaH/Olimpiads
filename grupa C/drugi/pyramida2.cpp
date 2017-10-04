#include<iostream>
using namespace std;
int a[1004][1004],st[1004][1004],rd[1004][1004],n;
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
        rd[i][j]=j;
      }
      if(st[i+1][j]<st[i+1][j+1])
      {
        st[i][j]=a[i][j]+st[i+1][j+1];
        rd[i][j]=j+1;
      }
    }
  }
  cout<<st[1][1]<<endl;
  int col=1;
  cout<<1<<" "<<1<<endl;
  for(int i=1;i<n;i++)
  {
    col=rd[i][col];
    cout<<i+1<<" "<<col<<endl;
  }
  return 0;
}
