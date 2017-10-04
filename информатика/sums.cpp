#include<iostream>
using namespace std;
int n,a[500],f[50505],s;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  f[0]=1;
  for(int i=0;i<n;i++)
  {
    for(int j=50000;j>=0;j--)
    {
      if(f[j]==1)f[j+a[i]]=1;
    }
  }
  for(int i=0;i<=50000;i++)if(f[i]==1)s++;
  cout<<s<<endl;
  return 0;
}
