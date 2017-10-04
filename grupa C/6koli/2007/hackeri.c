#include<iostream>
#include<string>
using namespace std;
string a,b,c;
int main()
{
  cin>>a;
  long n=a.size(),m,k=n-2,l;
  for(int i=n-1;i>=0;i--)
  {
    b=a.substr(i+1,n-i);
    //cout<<b<<endl;
    m=b.size();
    l=1;
    for(int j=0;j<m/2;j++)
    {
      if(b[j]!=b[m-j-1])
      {
        l=0;break;
      }
    }
    if(l==1)k=n-i-1;
    //cout<<k<<endl;
  }
  b=a;
  b.erase(n-k,k);
  //cout<<b<<endl;
  m=b.size();
  cout<<a;
  for(int i=m-1;i>=0;i--)cout<<b[i];
  cout<<endl;
  return 0;
}
