#include<iostream>
#include<string>
using namespace std;
int k;
string n;
int main()
{
  cin>>k;
  cin>>n;
  int c=0,d=n.size(),ost=0;
  for(int i=0;i<d;i++)
  {
    ost=(ost*10+n[i]-'0')%k;
  }
  cout<<ost<<endl;
  return 0;
}
