#include<iostream>
using namespace std;
int tab[105][105],vl[105],m,n,r1,r2,nov[105],pr;
void input()
{
  for(int i=0;i<=105;i++)
  {
    tab[i][0]=0;vl[i]=0;
  }
  cin>>n>>m;

  for(int i=1;i<=m;i++)
  {
    cin>>r1>>r2;cout<<"?"<<endl;
    tab[r1][0]++;
    tab[r1][tab[r1][0]]=r2;
    vl[r2]++;
  }
}
void solve(int vrah)
{
  pr++;
  nov[vrah]=pr;
  for(int i=1;i<=tab[vrah][0];i++)
  {
    vl[tab[vrah][i]]--;
    if(vl[tab[vrah][i]]==0)solve(tab[vrah][i]);
  }
}
int main()
{
  input();
  for(int i=1;i<=n;i++)if(vl[i]==0)solve(i);
  for(int i=1;i<=n;i++)cout<<i<<" "<<nov[i]<<endl;
  return 0;
}
