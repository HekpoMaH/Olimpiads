#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[203][203],d1,d2,col[203],colors;
void solve(int cr)
{
  int i,j;
  bool iscol,neighbcol;
  if(cr<=n)
  {
    iscol=false;
    i=col[cr]+1;
    while(!iscol&&i<=colors)
    {
      j=1;
      neighbcol=false;
      while(!neighbcol&&j<=a[cr][0])
      {
        if(col[a[cr][j]]==i)neighbcol=true;
        j++;
      }
      //cout<<"ima li sasedi s tozi cvqt "<<neighbcol<<" i="<<i<<endl;
      if(!neighbcol)
      {
        iscol=true;
        col[cr]=i;
        //cout<<"i="<<i<<endl;
      }
      i++;
    }
    if(iscol==true)solve(cr+1);
    else
    {
      //cout<<"iscol="<<iscol<<endl;
      col[cr]=0;
      if(cr>=2)solve(cr-1);
      else
      {
        colors++;
        solve(1);
      }
    }
  }
}
int main()
{
  scanf("%d",&n);
  while(scanf("%d%d",&d1,&d2)==2)
  {
    //cin>>d1>>d2;
    a[d1][0]++;a[d1][a[d1][0]]=d2;
    a[d2][0]++;a[d2][a[d2][0]]=d1;
  }
  /*for(int i=1;i<=n;i++)
  {
    cout<<i<<"->";
    for(int j=1;j<=a[i][0];j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }*/
  solve(1);
  printf("%d\n",colors);
  for(int i=1;i<=n;i++)
  {
    printf("%d ",col[i]);
  }
  printf("\n");
  return 0;
}
