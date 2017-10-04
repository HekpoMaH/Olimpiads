#include<iostream>
#include<queue>
using namespace std;
long long sum,n,a[1000004],f,l,s,br;
queue<long long> q;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>s;
  for(int i=0;i<n;i++)cin>>a[i];
  sum=a[0];
  while(1)
  {
    //cout<<sum<<" "<<s<<endl;
    if(sum<=s)
    {
      if(sum==s)
      {
        sum-=a[f];
        f++;//cout<<br<<endl;
        br++;
      }
      else
      {
        l++;sum+=a[l];

      }
    }
    else
    {
      sum-=a[f];
      if(f==l)
      {
        l++;f++;
        sum+=a[l];
      }
      else f++;
    }
    if(l==n)break;
  }
  cout<<br<<endl;
  return 0;
}
