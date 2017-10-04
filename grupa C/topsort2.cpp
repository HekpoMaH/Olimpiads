#include<iostream>
using namespace std;
int a[100][100],vl[100],nov[100],n,m,x,y,pr;
void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    a[x][0]++;
    a[x][a[x][0]]=y;
    vl[y]++;
  }
}
void solve(int x)
{
  pr++;
  nov[x]=pr;
  for(int i=1;i<=a[x][0];i++)
  {
    vl[a[x][i]]--;
    if(vl[a[x][i]]==0)solve(a[x][i]);
  }
}
int main()
{

  input();
  for(int i=1;i<=n;i++)if(vl[i]==0)solve(i);
  for(int i=1;i<=n;i++)cout<<i<<" "<<nov[i]<<endl;
  return 0;
}
