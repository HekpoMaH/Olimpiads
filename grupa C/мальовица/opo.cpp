#include<iostream>
#include<vector>
using namespace std;
vector<int> tree[10004];
int n,k;
int gs[10004];
int rem[10006],iz[10005],br;
void read()
{
  cin>>k>>n;
  int j;
  for(int i=2;i<=n;i++)
  {
    cin>>j;
    tree[j].push_back(i);
  }
}
void dfs(int at)
{
  gs[at]=1;
  rem[at]=0;
  for(int i=0;i<tree[at].size();i++)
  {
    int next=tree[at][i];
    dfs(next);
    gs[at]+=gs[next];
    rem[at]+rem[next];
  }
  if(gs[at]>=k)
  {
    iz[br]=at;
    br++;
    gs[at]=0;
    rem[at]++;
  }
}
int main()
{
  read();
  dfs(1);
  cout<<br<<endl;
  sort(iz,iz+br);
  cout<<iz[0];
  for(int i=1;i<br;i++)
  {
    cout<<" "<<iz[i];
  }
  cout<<endl;
  return 0;
}
