#include<iostream>
using namespace std;
int n,m,r1,r2,a[105][105],used[105],br,st,end;
void dfs(int vrah,int pos)
{
  used[vrah]=1;
  int nam=0;
  //cout<<vrah<<endl;
  if(vrah==pos)br++;
  for(int i=1;i<=a[vrah][0];i++)
  {
    //cout<<a[vrah][0]<<" ";
    if(used[a[vrah][i]]==0){dfs(a[vrah][i],pos);used[a[vrah][i]]=0;}
  }
  //cout<<"aaa"<<endl;
}
int main()
{
  cin>>n>>m;
  br=0;
  for(int i=0;i<=n;i++)
  {
    used[i]=0;a[i][0]=0;
  }
  for(int i=0;i<m;i++)
  {
    cin>>r1>>r2;
    a[r1][0]++;
    a[r1][a[r1][0]]=r2;
    a[r2][0]++;
    a[r2][a[r2][0]]=r1;
  }
  cin>>st>>end;
  dfs(st,end);
  cout<<br<<endl;
  return 0;
}
