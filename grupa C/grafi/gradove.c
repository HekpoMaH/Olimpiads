#include<iostream>
#include<vector>
using namespace std;
vector<int>g[105];
int n,m,a,b,used[105],beg=0,e=1,br=1,bfs[105],st,ft,c;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin>>st>>ft;
  used[st]=1;
  bfs[0]=st;
  while(beg!=e)
  {
    c=bfs[beg];
    for(int i=g[c].size()-1;i>=0;i--)
    {
      if(used[g[c][i]]==0)
      {
        bfs[e]=g[c][i];used[bfs[e]]=used[c]+1;e++;
      }
    }
    beg++;
  }//for(int i=0;i<=n;i++)cout<<used[i]<<endl;
  cout<<used[ft]-1<<endl;
  return 0;
}
