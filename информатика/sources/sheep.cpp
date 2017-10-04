#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int n,k;
long of[1009];
bool verno(int kap)
{
  int used[1009];
  int ans=0,vz=0,ost;for(int i=0;i<1009;i++)used[i]=0;

  while(vz<n)
  {
    ans++;
    if(ans>k)return false;
    ost=kap;
    for(int i=0;i<n;i++)
    {
      if(used[i]==0)
      {
        if(ost>=of[i])
        {
          used[i]=1;
          ost-=of[i];
          vz++;
        }
      }
    }
  }
  return true;
}
int main()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)cin>>of[i];
  sort(of,of+n,greater <int>());
  int br=n-1;
  long long lt,rt=0,mid;
  lt=of[0];
  for(int i=0;i<n;i++)rt+=of[i];
  //for(int i=0;i<n/2;i++)swap(of[i],of[n-i-1]);
  //for(int i=0;i<n;i++)cout<<of[i]<<" ";
  //cout<<endl;
  long long int otg=rt;
  while(lt<=rt)
  {
    mid=(lt+rt)/2;
    if(verno(mid)==1)
    {
      rt=mid-1;
      otg=mid;
    }
    else lt=mid+1;
  }
  cout<<otg<<endl;
  return 0;
}

