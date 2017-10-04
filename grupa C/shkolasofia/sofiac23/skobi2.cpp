#include<iostream>
#include<string>
using namespace std;
string s;
int n;
int main()
{
  ios::sync_with_stdio(false);
  cin>>s;
  for(int i=0;i<s.size();i++)
  {
    for(int j=i;j<s.size();j++)
    {
      if((j-i-1)%2==0&&s[i]==s[j])
      {
        s.erase(i,1);
        s.erase(j,1);
        i=1;
        break;
      }
    }
  }
  cout<<s<<endl;
  return 0;
}
