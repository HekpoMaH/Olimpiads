#include<iostream>
using namespace std;
char g[100][100],g2[100][100];
int used[100][100];
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};int n,m,si,sj,b=0,e=1,i1,j1,ei,ej;
pair<int,int>q[10010];
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
    cin>>g[i][j];
    if(g[i][j]=='*')
    {
      si=i;
      sj=j;
    }
    if(g[i][j]=='E')
    {
      ei=i;
      ej=j;
    }
  }
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
    cin>>g2[i][j];
  }
  pair<int,int>a;
  a=make_pair(si,sj);
  q[0]=a;
  used[si][sj]=1;
  while(b!=e)
  {
    a=q[b];
    for(int i=0;i<4;i++)
    {
      i1=a.first+mx[i];
      j1=a.second+my[i];
      if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&(g[i1][j1]!='#'||g2[i1][j1]!='#')&&used[i1][j1]==0)
      {
        used[i1][j1]=used[a.first][a.second]+1;
        q[e]=make_pair(i1,j1);
        e++;
      }
    }
    b++;
  }
  cout<<used[ei][ej]-1<<endl;
  //for(int i=0;i<=n;i++){for(int j=0;j<=n;j++)cout<<g[i][j];cout<<endl;}
  return 0;
}
