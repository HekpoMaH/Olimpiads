#include<iostream>
using namespace std;
int tab[105][105];
long long int sum=0;
int m,n,r,k;
int goThrough(int x, int y, int s)
{
  if(s==0&&tab[x][y]!=-1)
  {
    sum+=tab[x][y];
    tab[x][y]=-1;
  }
  if(s!=0)
  {
    if(x<m)
    {
      goThrough(x+1,y,s-1);
    }
    if(x>1)
    {
      goThrough(x-1,y,s-1);
    }
    if(y<n)
    {
      goThrough(x,y+1,s-1);
    }
    if(y>1)
    {
      goThrough(x,y-1,s-1);
    }
  }
}
int main()
{
  cin>>m>>n>>r>>k;
  int ir,jr;
  int o=0;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      ++o;
      tab[i][j]=o;
      if(o==r)
      {
        ir=i;
        jr=j;
      }
    }
  }
  goThrough(ir,jr,k);
  cout<<sum<<endl;
  return 0;
}
