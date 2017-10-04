#include<iostream>
using namespace std;
struct mat
{
  long long a[100][100];
};
mat a;
int n,x,y;
int m;
mat umn(mat m1,mat m2)
{
  mat c;
  unsigned long long s;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      s=0;
      for(int k=1;k<=n;k++)
      {
        s+=(m1.a[i][k]*m2.a[k][j]);
      }
      c.a[i][j]=s;
    }
  }
  return c;

}
void povd(unsigned long long t,mat &k)
{
    k=a;
   mat s=k;
  while(t!=0)
  {
    if(t&1){k=umn(k,s);}
    s=umn(s,s);
    t=t>>1;
  }
}
int main()
{
    cin>>n>>m;int br=0;
    for(int i=1;i<=m;i++)cin>>x>>y,a.a[x][y]=1;
    for(int i=3;i<=n;i++)
    {
        a=umn(a,a);
        for(int i1=1;i1<=n;i1++)
        {
            for(int i2=1;i2<=n;i2++)br+=a.a[i1][i2];
        }
    }
    cout<<br<<endl;
}
