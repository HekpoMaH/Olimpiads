#include<iostream>
using namespace std;
int m,n,r,k;
int field[103][103];
int i1=0;
int omg[1000];
int trs(int posy,int posx, int hodl)
{
  if(hodl == 0)
  {
    int br =0;
    for(int i=0;i<i1;i++)
    {
      if(field[posy][posx]!=omg[i])
      {++br;}
    }
    if(br==i1)
    {
    omg[i1] = field[posy][posx];
    ++i1;
    }
    return field[posy][posx];
  }
  if(field[posy+1][posx]!=0)
  {
    trs(posy+1,posx,hodl-1);
  }
  if(field[posy][posx+1]!=0)
  {
    trs(posy,posx+1,hodl-1);
  }
  if(field[posy-1][posx]!=0)
  {
     trs(posy-1,posx,hodl-1);
  }
  if(field[posy][posx-1]!=0)
  {
    trs(posy,posx-1,hodl-1);
  }
  return 0;
}
int main()
{
  cin>>m>>n>>r>>k;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      field[i][j] = (i-1)*n+j;
    }
  }
  //omg[0] = r;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(field[i][j] == r)
      {
        trs(i,j,k);
      }
    }
  }
  int s =0;
  for(int i=0;i<i1;i++)
  {
    s+=omg[i];
  }
  cout<<s<<endl;
  return 0;
}
