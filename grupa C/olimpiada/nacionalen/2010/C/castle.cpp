#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long long n,m,ans=20000;
string tab[55];
struct point
{
	int row,col,moves;
	bool operator < (const point& r) const
		{return row != r.row ? row < r.row : col < r.col;}
	point(int row_ = 0, int col_ = 0) {row = row_; col = col_; moves = 0;}
};
point eli;
point izhod;
vector<point> prince;
//vector<int> princex;
//vector<int> princey;
int find(point start, point finish)
{
  point cur,next;
  queue<point> q;
  q.push(start);
  int used[55][55],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
  for(int i=0;i<55;i++)
  {
    for(int j=0;j<55;j++)
    {
      used[i][j]=0;
    }
  }
  used[start.row][start.col]=1;
  while(!(q.empty()))
  {
    cur=q.front();
    q.pop();//cout<<cur.row<<" "<<finish.row<<" "<<cur.col<<" "<<finish.col<<endl;
    if(cur.row==finish.row&&cur.col==finish.col){return cur.moves;cout<<"basi"<<endl;}
    next.moves=cur.moves+1;
    for(int i=0;i<4;i++)
    {
      next.row=(cur.row+dx[i]+n)%n;
      next.col=(cur.col+dy[i]+m)%m;
      if(tab[next.row][next.col]=='#')continue;
      if(used[next.row][next.col]==0)
      {//cout<<"basi"<<endl;
        q.push(next);
        used[next.row][next.col]=1;
      }
    }
  }
  return 20000;
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>tab[i];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(tab[i][j]=='E'){eli.row=i;eli.col=j;tab[i][j]='.';}
      if(tab[i][j]=='X'){izhod.row=i;izhod.col=j;tab[i][j]='.';}
      if(tab[i][j]=='P'){prince.push_back(point(i,j));tab[i][j]='.';}
      //cout<<tab[i][j];
    }
    //cout<<endl;
  }
  if(prince.empty())ans=find(eli,izhod);
  else
  {
    sort(prince.begin(),prince.end());
    do
    {
      int cur=0;
      cur+=find(eli,prince[0]);
      for(int i=1;i<(int)prince.size();i++)cur+=find(prince[i-1],prince[i]);
      cur+=find(prince.back(),izhod);
      if(cur<ans)ans=cur;//cout<<ans<<" "<<cur<<endl;
    }while(next_permutation(prince.begin(),prince.end()));
  }
  if(ans==20000)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}
