#include<iostream>
#include<string>
using namespace std;
long n,m[256],d,mn;
char mc;
string a;
int main()
{
  cin>>n;
  for(int i=0;i<=n;i++)
  {
    getline(cin,a);
    d=a.size();
    for(int j=0;j<d;j++)
    {
      m[(int)a[j]]++;
      if(m[(int)a[j]]>mn&&a[j]!=' '){mn=m[(int)a[j]];mc=a[j];}
    }
    for(int j=0;j<=256;j++)m[j]=0;
  }
  cout<<mc<<" "<<mn<<endl;
  return 0;
}
