#include<iostream>
#include<vector>
using namespace std;
vector<int>g[550];
int n,m,a,b,used[550],beg=0,e=1,bfs[550],st,ft,c,l,br=0;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;if(i==0)st=a;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  l=1;
  while(l!=0)
  {
    for(int i=0;i<n;i++)if(used[i]==0){st=i;}
    used[st]=1;
    beg=0;e=1;
    for(int i=0;i<500;i++)bfs[i]=0;
    bfs[0]=st;
  while(beg!=e)
  {
    c=bfs[beg];
    for(int i=g[c].size()-1;i>=0;i--)
    {
      if(used[g[c][i]]==0)
      {
        bfs[e]=g[c][i];used[bfs[e]]=1;e++;
      }
    }
    beg++;
  }
  br++;
  l=0;
  for(int i=0;i<n;i++)/*cout<<used[i]<<endl;*/if(used[i]!=1)l=1;
  }
  cout<<br-1<<endl;
  return 0;
}
