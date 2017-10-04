#include<iostream>
#include<queue>
using namespace std;
 long long a[101][101],ind[101][101],i,j,k,r,br,x,y,n,m,sum;
 queue<long long> qx,qy;
 int wmykni (int x1,int y1)
 {
   if (x1>=1&&x1<=n&&y1>=1&&y1<=m&&ind[x1][y1]+1<=k)
   {qx.push(x1); qy.push(y1); ind[x1][y1]=ind[x][y]+1; if (ind[x1][y1]==k+1) {sum+=a[x1][y1];}}
 }
int main()
{
  cin>>n>>m>>r>>k;
  br=1;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
    {
      a[i][j]=br;
      br++;
    }
  }
  x=(r/m)+1;
  y=r%m; if(y==0) {y=m; x--;}
  qx.push(x);
  qy.push(y);
  ind[x][y]=1;
  while (1==1)
  {
    x=qx.front();
    y=qy.front();
    if (ind[x][y]==k+1) {break;}
    wmykni(x-1,y);
    wmykni(x+1,y);
    wmykni(x,y-1);
    wmykni(x,y+1);
    qx.pop();
    qy.pop();

  }
  cout<<sum<<endl;
  return 0;
}