#include<iostream>
#include<vector>
using namespace std;
int n,a,b,p,st,ft,used[13],bfs[14],br=-1,gradove[13];
vector<int>g[12];
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  for(int j=i+1;j<n;j++)
  {
    //cout<<i<<" "<<j<<endl;
    cin>>a>>b>>p;
    if(p==1){g[a].push_back(b);g[b].push_back(a);}
  }
  cin>>st>>ft;
  used[st]=1;
  bfs[0]=st;
  int c,beg=0,e=1;
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
    br++;gradove[br]=bfs[beg];
    beg++;
  }
  cout<<used[ft]<<endl;
  if(used[ft]!=0){cout<<gradove[0];for(int i=1;i<=br;i++)cout<<" "<<gradove[i];cout<<endl;}
  return 0;
}
