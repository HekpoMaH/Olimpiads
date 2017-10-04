#include<iostream>
using namespace std;
int k,n,d,k1,k2,br;
string a;
int main()
{
  cin>>k;
  cin>>a;
  d=a.size();
  int i=0;
  while(i<d)
  {
    if(a[i]>='0'&&a[i]<='9'&&a[i-1]!='-')
    {
      if(a[i]!='0')n+=a[i]-'0'+3;
      else n++;
    }
  }
  int ta[n],m[d/2];
  while(i<d)
  {
    if(a[i]>='0'&&a[i]<='9'&&a[i-1]!='-')
    {
      br++;
      if(a[i-1]=='-'&&a[i]=='1')m=-1;
    }
  }