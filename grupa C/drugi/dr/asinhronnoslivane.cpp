#include<iostream>
using namespace std;
int n,m,a[105],b[105],c[210];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  cin>>m;
  for(int i=1;i<=m;i++)cin>>b[i];
  int i=1,j=1,br=1;
  while(i<=n&&j<=m)
  {
    //cout<<a[i]<<" "<<b[j]<<" "<<j<<endl;
    if(a[i]==b[j])
    {
      c[br]=a[i];
      br++;i++;
      c[br]=b[j];
      br++;j++;
    }
    if(a[i]<b[j])
    {
      c[br]=a[i];
      i++;br++;
    }
    if(a[i]>b[j])
    {
      c[br]=b[j];
      j++;
      br++;
    }
  }
  while(i<=n)
  {
    c[br]=a[i];
    br++;i++;
  }
  while(j<=m)
  {
    c[br]=b[j];
    br++;j++;
  }
  for(int i=1;i<br;i++)cout<<c[i]<<" ";
  cout<<endl;
  return 0;
}
