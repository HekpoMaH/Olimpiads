#include<iostream>
#include<string>
#include<queue>
using namespace std;
int pole[9][9],stx,sty,ex,ey;
string s;
int n,minp,msum=99999;
struct cube
{
  int front,back,bottom,top,left,right;
};
cube c;
int bfs(int stx,int sty)
{
  queue<int> x;queue<int> y;
  x.push(stx);y.push(sty);
  int tx,ty;
  int used[9][9];
  for(int i=0;i<=9;i++)for(int j=0;j<=9;j++)used[i][j]=0;
  used[stx][sty]=1;
  while(x.size()>0)
  {
    tx=x.front();ty=y.front();
    //cout<<tx<<" "<<ty<<endl;
    x.pop();y.pop();
    //cout<<used[tx+1][ty]<<endl;
    //cout<<used[tx-1][ty]<<endl;
    //cout<<used[tx][ty+1]<<endl;
    //cout<<used[tx][ty-1]<<endl;
    if(tx+1<9&&used[tx+1][ty]==0&&pole[tx+1][ty]!=1)
    {
      used[tx+1][ty]=used[tx][ty]+1;
      x.push(tx+1);y.push(ty);
    }
    if(tx-1>0&&used[tx-1][ty]==0&&pole[tx-1][ty]!=1)
    {
      used[tx-1][ty]=used[tx][ty]+1;
      x.push(tx-1);y.push(ty);
    }
    if(ty+1<9&&used[tx][ty+1]==0&&pole[tx][ty+1]!=1)
    {
      used[tx][ty+1]=used[tx][ty]+1;
      x.push(tx);y.push(ty+1);
    }
    if(ty-1>0&&used[tx][ty-1]==0&&pole[tx][ty-1]!=1)
    {
      used[tx][ty-1]=used[tx][ty]+1;
      x.push(tx);y.push(ty-1);
    }
  }
  return used[ex][ey]-1;
}
cube cnew;
int usd[9][9];
void recurse(cube c,int cx,int cy,int p,int sum)
{
  if(cx==ex&&cy==ey&&sum<msum){msum=sum;return;}
  if(pole[cx-1][cy]!=1&&usd[cx-1][cy]==0&&p+1<=minp&&sum+c.back<msum)
  {
    cnew.front=c.bottom;
    cnew.bottom=c.back;
    cnew.top=c.front;
    cnew.back=c.top;
    cnew.left=c.left;
    cnew.right=c.right;
    usd[cx-1][cy]=1;
    recurse(cnew,cx-1,cy,p+1,sum+c.back);
    usd[cx-1][cy]=0;
  }
  if(pole[cx+1][cy]!=1&&usd[cx+1][cy]==0&&p+1<=minp&&sum+c.front<msum)
  {
    cnew.front=c.top;
    cnew.back=c.bottom;
    cnew.top=c.back;
    cnew.bottom=c.front;
    cnew.left=c.left;
    cnew.right=c.right;
    usd[cx+1][cy]=1;
    recurse(cnew,cx+1,cy,p+1,sum+c.front);
    usd[cx+1][cy]=0;
  }
  if(pole[cx][cy+1]!=1&&usd[cx][cy+1]==0&&p+1<minp&&sum+c.right<msum)
  {
    cnew.front=c.front;
    cnew.back=c.back;
    cnew.top=c.left;
    cnew.bottom=c.right;
    cnew.left=c.bottom;
    cnew.right=c.top;
    usd[cx][cy+1]=1;
    recurse(cnew,cx,cy+1,p+1,sum+c.right);
    usd[cx][cy+1]=0;
  }
  if(pole[cx][cy-1]!=1&&usd[cx][cy-1]==0&&p+1<minp&&sum+c.left<msum)
  {
    cnew.front=c.front;
    cnew.back=c.back;
    cnew.top=c.right;
    cnew.bottom=c.left;
    cnew.left=c.top;
    cnew.right=c.bottom;
    usd[cx][cy-1]=1;
    recurse(cnew,cx,cy-1,p+1,sum+c.left);
    usd[cx][cy-1]=0;
  }
}
int main()
{
  cin>>s;
  sty=s[0]-'a'+1;
  stx=8-(s[1]-'0')+1;
  cin>>s;
  ey=s[0]-'a'+1;
  ex=8-(s[1]-'0')+1;
  //cout<<stx<<" "<<sty<<endl<<ex<<" "<<ey;
  cin>>c.front>>c.back>>c.top>>c.right>>c.bottom>>c.left;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    pole[8-(s[1]-'0')+1][s[0]-'a'+1]=1;
  }
  minp=bfs(stx,sty);
  //cout<<minp<<endl;
  usd[stx][sty]=1;
  recurse(c,stx,sty,0,0);
  cout<<msum<<endl;
  return 0;
}
