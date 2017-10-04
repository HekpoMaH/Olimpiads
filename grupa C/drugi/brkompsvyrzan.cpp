#include<iostream>
using namespace std;
int n,m,r1,r2,a[105][105],used[105],br;
void dfs(int vrah)
{
  used[vrah]=1;
  //cout<<vrah<<endl;
  for(int i=1;i<=a[vrah][0];i++)
  {
    //cout<<a[vrah][0]<<" ";
    if(used[a[vrah][i]]==0){dfs(a[vrah][i]);}
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
  int fl=1,st=1;
  while(fl==1)
  {
    br++;
    fl=0;
    dfs(st);
    for(int i=1;i<=n;i++)
    {
      if(used[i]==0){st=i;fl=1;break;}
    }
  }
  cout<<br<<endl;
  return 0;
}
