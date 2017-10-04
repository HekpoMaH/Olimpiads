#include<iostream>
using namespace std;
long long k,n,a[1000],mx,tk;
int main()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n-k;i++)
  {
    tk=0;
    for(int j=i;j<i+k;j++)
    {
      tk+=a[j];
    }
    if(tk>mx)mx=tk;
  }
  cout<<mx<<endl;
  return 0;
}
