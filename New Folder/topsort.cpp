#include<iostream>
using namespace std;
int tab[105][105],n,m,vl[105],r1,r2,cnt,nov[105];
void input()
{
  cin>>n>>m;
  for(int i=0;i<=105;i++)
  {
    tab[i][0]=0;vl[i]=0;
  }
  for(int i=1;i<=m;i++)
  {
    cin>>r1>>r2;
    tab[r1][0]++;vl[r2]++;
    tab[r1][tab[r1][0]]=r2;
  }
}
void solve(int vrah)
{
  cnt++;
  nov[vrah]=cnt;
  for(int i=1;i<=tab[vrah][0];i++)
  {
    vl[tab[vrah][i]]--;
    if(vl[tab[vrah][i]]==0)solve(vrah);
  }
}
int main()
{
  input();
  for(int i=1;i<=n;i++)if(vl[i]==0)solve(i);
  for(int i=1;i<=n;i++)cout<<i<<" "<<nov[i]<<endl;
  return 0;
}

