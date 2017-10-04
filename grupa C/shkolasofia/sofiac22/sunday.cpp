#include<iostream>
#include<algorithm>
using namespace std;
long long r,c,n,p[100003],raz[100003];
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>r>>c;
  for(int i=1;i<=n;i++)cin>>p[i];
  sort(p,p+n+1);
  for(int i=1;i<=n-c+1;i++)raz[i]=p[i+c-1]-p[i];
  long long k=n-c+1;
  sort(raz,raz+k+1);
  cout<<raz[r]<<endl;
  return 0;
}
