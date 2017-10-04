#include<iostream>
using namespace std;
int a[9][9],n,m,d1,d2,s;
int main()
{
  cin>>n>>m;
  a[m][n]=1;
  for(int i=m+1;i<=8;i++)
  {
    for(int j=1;j<=8;j++)
    {
      d1=0;
      d2=0;
      d1=a[i-1][j-1];
      d2=a[i-1][j+1];
      a[i][j]=d1+d2;
    }
  }
  for(int i=1;i<=8;i++)s+=a[8][i];
  cout<<s<<endl;
  return 0;
}
