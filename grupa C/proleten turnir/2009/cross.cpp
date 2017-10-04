#include<iostream>
using namespace std;
int n,m,tab[205][205],used[205],a,b,g,p,s,sk,br,pe[250][250],go[250][250],ko;
int dfs(int vrah,int hodove,int pos)
{
  int nam=0;
  used[vrah]=1;
  if(vrah==pos)
  {
    if(ko==0)pe[vrah][hodove]=1;
    else go[vrah][hodove]=1;
    return 1;
  }
  for(int i=0;i<n;i++)
  {
    if(tab[vrah][i]==1&&used[i]==0)
    {
      nam=max(nam,dfs(i,hodove+1,pos));
      used[i]=0;
    }
  }
  if(nam==1)
  {
    if(ko==0)pe[vrah][hodove]=1;
    else go[vrah][hodove]=1;
  }
  return nam;
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    tab[a][b]=1;
    tab[b][a]=1;
  }
  cin>>p>>s>>g>>sk;
  int ni6to;
  ni6to=dfs(p,0,s);
  ko=1;
  for(int i=0;i<205;i++)used[i]=0;
  ni6to=dfs(g,0,sk);
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      if(go[i][j]==1&&pe[i][j]==1){br++;break;}
    }
  }
  cout<<br<<endl;
  return 0;
}
