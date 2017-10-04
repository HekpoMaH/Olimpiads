#include<iostream>
#include<vector>
using namespace std;
long long n,t,l,br,a[100000],m[100000],used[100000];
void perm(int s)
{
  if(s>=n)
  {
    br++;
    br%=1000000000;
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      //cout<<used[i]<<" "<<a[i]<<" "<<i<<endl;
      for(int j=i;j<n;j++)
      if(used[j]==0)
      {
        m[s]=a[j];
        used[j]=1;
        perm(s+1);
        used[j]=0;
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++)a[i]=i;
  perm(0);
  cout<<br<<endl;
  return 0;
}
