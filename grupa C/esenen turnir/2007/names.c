#include<iostream>
using namespace std;
struct geroi
{
  string name;
  long long brs;
};
geroi g[1000001];
string tg,gg;
int br=-1,n,l;
int mx=-1;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>tg;
    l=0;
    for(int i=0;i<=br;i++)if(g[i].name==tg){l=1;g[i].brs++;}
    if(l==0)
    {
      br++;
      g[br].name=tg;
    }
  }
  for(int i=0;i<=br;i++){if(g[i].brs>mx){mx=g[i].brs;gg=g[i].name;}}
  cout<<gg<<endl;
  return 0;
}
