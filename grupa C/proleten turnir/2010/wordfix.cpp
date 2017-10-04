#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> g[500];
string s1,s2;
long long pos[500],ans;
int main()
{
  ios::sync_with_stdio(false);
  cin>>s1>>s2;
  int d=s1.size();
  for(int i=0;i<d;i++)
  {
    g[(int)s2[i]].push_back(i);
  }
  for(int i=0;i<d;i++)
  {
    if(i>g[(int)s1[i]][pos[(int)s1[i]]])ans+=i-g[(int)s1[i]][pos[(int)s1[i]]];
    pos[(int)s1[i]]++;
  }
  cout<<ans<<endl;
  return 0;
}
