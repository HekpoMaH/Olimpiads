#include<iostream>
using namespace std;
int tab[12][12],m,n,s[8],mx,tab2[4];
int main()
{
  cin>>m>>n;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>tab[i][j];
    }
  }
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      tab2[0]=tab[i][j+1];
      tab2[1]=tab[i][j-1];
      tab2[2]=tab[i+1][j];
      tab2[3]=tab[i-1][j];
      sort(tab2,tab2+4);
      if(tab[i][j]+tab2[3]+tab2[2]>mx)mx=tab[i][j]+tab2[3]+tab2[2];
    }
  }
  cout<<mx<<endl;
  return 0;
}
