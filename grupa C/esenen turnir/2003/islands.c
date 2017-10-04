#include<iostream>
#include<string>
using namespace std;
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};
int l;
int si,sj;
bool used[1000][1000];
int g[1005][1005],n,br=-1;
//pair<int,int> q[1000203];
//pair<int,int>zt[1000203];
char c;
int i1,j1,b,e=1,bro;
void dfs(int x,int y)
{
  int i2=x,j2=y;
  for(int i=0;i<4;i++)
  {
    i2=x;j2=y;
    i2+=mx[i];j2+=my[i];//cout<<bro<<endl;
    if(i2>=0&&i2<n&&j2>=0&&j2<n&&g[i2][j2]==1&&used[i2][j2]==0)
    {
      used[i2][j2]=1;
      dfs(i2,j2);
    }
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)
  {
    cin>>c;
    if(c=='*'){g[i][j]=1;si=i;sj=j;l=1;}
    else{g[i][j]=0;used[i][j]=1;}
  }
  //pair<int,int>a;
  //q[0]=a;
  used[si][sj]=true;
  while(l!=0)
  {
    dfs(si,sj);
    //b=0;e=1;
    //a.first=si;a.second=sj;
    //q[0]=a;
    bro++;l=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)if(g[i][j]==1&&used[i][j]==0){l=1;si=i;sj=j;break;}
  }
  cout<<bro<<endl;
  return 0;
}
