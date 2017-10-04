#include<iostream>
using namespace std;
struct pr
{
  int y1,y2,y3,y4,y5,c;
};
pr prom[200];
int p[6][6][6][6][6],k[100],pp[100],b,s,br=b,x;
int main()
{
  ios::sync_with_stdio(false);
  cin>>b;
  for(int i=1;i<=b;i++)
  {
    cin>>k[i]>>pp[i];
    if(i==1){prom[i].y1=1;prom[i].c=pp[i];}
    if(i==2){prom[i].y2=1;prom[i].c=pp[i];}
    if(i==3){prom[i].y3=1;prom[i].c=pp[i];}
    if(i==4){prom[i].y4=1;prom[i].c=pp[i];}
    if(i==5){prom[i].y5=1;prom[i].c=pp[i];}
  }
  br=b;
  cin>>s;
  for(int i=1;i<=s;i++)
  {
    br++;
    for(int j=1;j<=b+1;j++)
    {
      cin>>x;
      if(j==1&&j!=b+1)prom[br].y1=x;
      if(j==2&&j!=b+1)prom[br].y2=x;
      if(j==3&&j!=b+1)prom[br].y3=x;
      if(j==4&&j!=b+1)prom[br].y4=x;
      if(j==5&&j!=b+1)prom[br].y5=x;
      if(j==b+1)prom[br].c=x;
    }
  }
  int xx1,xx2,xx3,xx4,xx5;
  //cout<<br<<endl;
  for(int x1=0;x1<=5;x1++)
  {
    for(int x2=0;x2<=5;x2++)
    {
      for(int x3=0;x3<=5;x3++)
      {
        for(int x4=0;x4<=5;x4++)
        {
          for(int x5=0;x5<=5;x5++)
          {
            for(int d=1;d<=br;d++)
            {
              if(x1>=prom[d].y1&&x2>=prom[d].y2&&x3>=prom[d].y3&&x4>=prom[d].y4&&x5>=prom[d].y5)
              {
                xx1=x1-prom[d].y1;xx2=x2-prom[d].y2;xx3=x3-prom[d].y3;xx4=x4-prom[d].y4;xx5=x5-prom[d].y5;
                if((p[xx1][xx2][xx3][xx4][xx5]+prom[d].c<p[x1][x2][x3][x4][x5]&&p[x1][x2][x3][x4][x5]!=0)||p[x1][x2][x3][x4][x5]==0)
                {
                  p[x1][x2][x3][x4][x5]=p[xx1][xx2][xx3][xx4][xx5]+prom[d].c;//cout<<p[x1][x2][x3][x4][x5]<<endl;
                  //cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<" "<<d<<endl;system("pause");
                }
              }
            }
          }
        }
      }
    }
  }
  cout<<p[k[1]][k[2]][k[3]][k[4]][k[5]]<<endl;
  return 0;
}
