#include<iostream>
using namespace std;
long long a[1300009],n,br;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;

  for(long long i=0;i<n;i++)cin>>a[i];
  br=1;sort(a,a+n);long long i;
  for( i=1;i<n;i++)
  {
    //cout<<a[i]<<endl;
    if(a[i]==a[i-1])br++;
    else
    {
      //cout<<a[i]<<" "<<a[i-1]<<" "<<br<<endl;
      if(br%2==1){cout<<a[i-1]<<endl;return 0;}
      br=1;
    }
  }
  if(br%2==1)cout<<a[i-1]<<endl;
  return 0;
}
