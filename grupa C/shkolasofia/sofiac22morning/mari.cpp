#include<iostream>
#include<string>
using namespace std;
long long m,n;
string s,ss="B";
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=0;i<=n;i++)
  {
    getline(cin,s);
    if(s==ss)cout<<"-1"<<endl;
  }
  return 0;
}
