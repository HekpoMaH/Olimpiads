#include<iostream>
#include<string>
using namespace std;
int n,p,k[105],s,d;
string a,b;
int main()
{
  cin>>n>>d;
  for(int i=0;i<=d;i++)cin>>k[i];
  cin>>p;
  s=k[0];
  for(int i=1;i<=d;i++){s=s*n+k[i];}
  //cout<<s<<endl;
  int ost;
  while(s>1)
  {
    ost=s%p;
    a+=ost+'0';
    n/=p;
  }
  a+=s+'0';
  reverse(a.begin(),a.end());
  while(a[0]=='0')a.erase(0,1);
  cout<<a<<endl;
  return 0;
}
