#include<iostream>
#include<string>
#include<vector>
using namespace std;
int used[10200],m,n,si,sj,x1,y1,md[10200],ind;
string s[102];
vector<int>g[102];
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};
void dfs(int nom)
{
  used[nom]=1;
  cout<<nom<<endl;
  int x=nom/n;
  int y=nom%n;
  for(int i=0;i<4;i++)
  {
    x1=x+mx[i];
    y1=y+my[i];
    if(x1>=0&&x1<m&&y1>=0&&y1<n&&s[x1][y1]!='#'&&used[x1+y1*n]==0)
    {
      dfs(x1+y1*n);
    }
  }
  return;
}
int main()
{
  cin>>m>>n;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
  {
    cin>>s[i][j];
    if(s[i][j]=='0')
    {
      si=i;sj=j;
    }
  }
  dfs(si+sj*n);
  return 0;
}
