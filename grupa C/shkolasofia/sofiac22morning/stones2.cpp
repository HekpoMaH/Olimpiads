#include<iostream>
using namespace std;
long long m,n;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>m;
    if(m%3==0)cout<<2;
    else cout<<1;
  }
  cout<<endl;
  return 0;
}
