#include<iostream>
using namespace std;
long long a[23][23],k,m,x,y;
long long nod(long long a,long long b)
{
  long long r;
  while(b!=0)
  {
    r=a%b;
    a=b;
    b=r;
  }//cout<<a<<endl;
  return a;
}
int main()
{
  cin>>k>>m;
  a[1][1]=1;
  for(int i=2;i<=k;i++)
  {
    a[i][1]=i;
    for(int j=2;j<=i;j++)
    {
      x=a[i-1][j-1]*a[i][j-1];
      y=a[i][j-1]-a[i-1][j-1];
      a[i][j]=x/nod(x,y);//cout<<i<<" "<<j<<endl;
    }
  }
  cout<<1<<endl<<"-"<<endl<<a[k][m]<<endl;
  return 0;
}
