#include<iostream>
using namespace std;
long long maxx,m,n,k,a[1005][1005],s,sp,spr;
int main()
{
  long long i,j,x;
  s=0;
  sp=0;
  maxx=0;
  cin>>m>>n>>k;

  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
      cin>>a[i][j];
      s=s+a[i][j];
    }

  for(i=1;i<=k;i++)
    for(j=1;j<=k;j++)
      sp=sp+a[i][j];
  maxx=sp;
  spr=sp;
  for(i=1;i<=m-k+1;i++)
    for(j=1;j<=n-k+1;j++)
    {
      if(i>1 && j==1)
      {
        for(x=1;x<=k;x++)
        {
          sp=sp-a[i-1][x];
          sp=sp+a[i+k-1][x];
        }
        spr=sp;
        if(sp>maxx)
          maxx=sp;
      }
      if(j>1)
      {
        for(x=i;x<=i+k-1;x++)
        {
          spr=spr-a[x][j-1];
          spr=spr+a[x][j+k-1];
        }
        if(spr>maxx)
          maxx=spr;
      }
    }
  cout<<s-maxx<<endl;
}
/*
3 4 2
1 1 1 2
2 3 4 1
2 1 9 2
*/
