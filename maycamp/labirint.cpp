#include<iostream>
using namespace std;
int tab[355][355],n;
int main()
{
  cin>>n;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<i;j++)
    {
      cin>>tab[i][j];
    }
  }
  for(int i=n-1;i>=0;i--)
  {
    for(int j=0;j<i;j++)
    {
      tab[i][j]+=max(tab[i+1][j],tab[i+1][j+1]);//cout<<i<<" "<<j<<" "<<tab[i][j]<<endl;
    }
  }
  cout<<tab[1][0]<<endl;//system("pause");
  return 0;
}
