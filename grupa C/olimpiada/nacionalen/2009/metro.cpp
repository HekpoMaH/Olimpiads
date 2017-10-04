#include<iostream>
using namespace std;
long long n,h[1005],price[1005][105],best;
int priceat(int d,int h1)
{
  if(h[d]==h1)return 1;
  if(h[d]>h1)return (h[d]-h1)*(h[d]-h1);
  return 7*(h1-h[d]);
}
void fromto(int dist,int curh,int nexth)
{
  if(nexth>=0&&nexth<100&&(price[dist+1][nexth]==0||price[dist+1][nexth]>price[dist][curh]+priceat(dist+1,nexth)))
  {
    price[dist+1][nexth]=price[dist][curh]+priceat(dist+1,nexth);
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>h[i];
  }
  for(int i=0;i<=100;i++)price[0][i]=priceat(0,i);
  for(int i=0;i<n-1;i++)
  {
    for(int j=1;j<100;j++)
    {
      fromto(i,j,j+1);
      fromto(i,j,j);
      fromto(i,j,j-1);
      fromto(i,j,j-2);
    }
  }
  best=100000000;
  for(int i=1;i<=100;i++)
  {
    //cout<<price[0][i]<<endl;
    if(best>price[n-1][i]&&price[n-1][i]>0)best=price[n-1][i];
  }
  cout<<best<<endl;
  return 0;
}
/*
7
19 16 15 18 20 20 21
*/
