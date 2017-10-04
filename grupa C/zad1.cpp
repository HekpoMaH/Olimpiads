#include<iostream>
using namespace std;
int n,a[15],m[20],used[20];
void var(int s,int k)
{
  if(s>=k)
  {
    for(int j=0;j<s;j++)
    {
      cout<<m[j];
    }
    cout<<endl;
  }
  else
  {
    for(int j=0;j<n;j++)
    {
      if(used[j]==0)
      {
        m[s]=a[j];
        used[j]=1;
        var(s+1,k);
        used[j]=0;
      }
    }
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)
  {
    var(0,i);
  }
  return 0;
}
