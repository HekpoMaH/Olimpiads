#include<iostream>
using namespace std;
int r[8][8],x[8][8];
void BT(int d[8][8],int k)
{
  //if(l==1)return;
  if(k==9)
  {
    for(int i=1;i<=8;i++)
    {
      for(int j=1;j<=8;j++)
      {
        cout<<r[i][j];
      }
      cout<<endl;
    }
    //l=1;
    //return;
  }
  for(int i=1;i<=8;i++)
  {
    if(d[k][i]==0)
    {
      r[k][i]=1;d[k][i]=1;
      for(int j=1;j<=8;j++)
      {
        if(k>j)d[k-j][i]+=1;
        if(i>k)d[k][i-j]+=1;
        if(k+j<=8)d[k+j][i]+=1;
        if(i+j<=8)d[k][i+j]+=1;
        if(k+j<=8&&i+j<=8)d[k+j][i+j]+=1;
        if(k>j&&i>j)d[k-j][i-j]+=1;
        if(k+j<=8&&i>j)d[k+j][i-j]+=1;
        if(k>j&&i+j<=8)d[k-j][i+j]+=1;
      }
      /*cout<<"k="<<k<<"i="<<i<<endl;
      for(int u=1;u<=8;u++)
      {
        for(int y=1;y<=8;y++)
        {
          cout<<d[u][y];
        }
        cout<<endl;
      }
      system("pause");*/
      BT(d,k+1);
      d[k][i]=0;
      for(int j=1;j<=8;j++)
      {
        if(k>j)d[k-j][i]--;
        if(i>k)d[k][i-j]--;
        if(k+j<=8)d[k+j][i]--;
        if(i+j<=8)d[k][i+j]--;
        if(k+j<=8&&i+j<=8)d[k+j][i+j]--;
        if(k>j&&i>j)d[k-j][i-j]--;
        if(k+j<=8&&i>j)d[k+j][i-j]--;
        if(k>j&&i+j<=8)d[k-j][i+j]--;
      }
      r[k][i]=0;
    }
  }
}
int main()
{
  BT(x,1);
  return 0;
}
