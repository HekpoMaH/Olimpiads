#include<iostream>
using namespace std;
long long x,y,br2,tab[65][65],d;
int main()
{
  cin>>x>>y;
  if(x%2==1||y%2==1){cout<<0<<endl;return 0;}
  tab[0][0]=1;
  for(int i=0;i<64;i++)
  {
    for(int j=0;j<64;j++)
  {
    d=0;
    if(i-2>=0)d+=tab[i-2][j];
    else d+=0;
    if(j-2>=0)d+=tab[i][j-2];
    else d+=0;
    tab[i][j]+=d;
    //cout<<tab[i][j]<<" ";//if(
  }
  //cout<<endl;
  }
  cout<<tab[x][y]<<endl;
  return 0;
}
