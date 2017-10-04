#include<iostream>
using namespace std;
long long n,x,y;
struct mat
{
  long long a[100][100];
};
mat m;
mat umn(mat m1,mat m2)
{
  mat c;
  long long s;
  for(int i=0;i<x;i++)
  {
    for(int j=0;j<x;j++)
    {
      s=0;
      for(int k=0;k<x;k++)
      {
        s+=m1.a[i][k]*m2.a[k][j];
      }
      c.a[i][j]=s;
    }
  }
  return c;
}
mat povd(long long t)
{
  mat k;
  //if(t==0)return 1;
  if(t==1)return m;
  if(t%2==0)k=umn(povd(t/2),povd(t/2));;
  if(t%2==1)k=umn(m,povd(t-1));
  return k;
}
int main()
{
  mat an;
  cin>>x;
  for(int i=0;i<x;i++)
  {
    for(int j=0;j<x;j++)
    {
      cin>>m.a[i][j];
    }
  }
  cin>>n;
  an=povd(n);
  cout<<an.a[0][0]+an.a[0][1]
  return 0;
}
