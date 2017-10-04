#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int x,m,n,ost,i1;
string s,s2;
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    i1=i;
    s2="";
    while(i1!=0)
    {
      s2+=i1%10+'0';
      i1/=10;
    }
    reverse(s2.begin(),s2.end());
    s+=s2;
  }
  //cout<<s<<endl;
  int d=s.size();
  ost=s[0]-'0';
  for(int i=1;i<d;i++)
  {
    ost%=m;
    ost=ost*10+(s[i]-'0');
  }
  ost%=m;
  cout<<ost<<endl;
  return 0;
}
