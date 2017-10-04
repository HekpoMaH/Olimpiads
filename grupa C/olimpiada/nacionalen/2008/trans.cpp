#include<iostream>
#include<string>
using namespace std;
string a,b;
int br,p,k,s;
int main()
{
  cin>>k>>a>>b;
  s=a.size();
  for(int i=0;i<s-k+1;i++)
  {
    p=(9+b[i]-a[i])%9;br+=p;
    for(int j=0;j<k;j++)a[i+j]='1'+(a[i+j]+p-'1')%9;
  }
  if(a==b)cout<<br<<endl;
  else cout<<0<<endl;
  return 0;
}
