#include<iostream>
#include<algorithm>
using namespace std;
int n,p[10000],s;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>p[i];
  sort(p,p+n);
  int i=n-1;
  while(i>=3)
  {
    s+=p[i]+p[i-1];
    i-=3;
  }
  for(int j=i;j>=0;j--)s+=p[j];
  cout<<s<<endl;
  return 0;
}
