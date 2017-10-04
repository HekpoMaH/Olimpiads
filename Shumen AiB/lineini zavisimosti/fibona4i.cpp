#include<iostream>
using namespace std;
long long n,x,y;
struct mat
{
  long long a[100][100];
};
long long mod;
mat m;
mat umn(mat m1,mat m2)
{
  mat c;
  long long s;
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      s=0;
      for(int k=0;k<2;k++)
      {
        s+=(m1.a[i][k]*m2.a[k][j])%mod;s%=mod;
      }
      c.a[i][j]=s;
    }
  }
  return c;

}
mat povd(long long t)
{
  mat k;
  bool y;
  k.a[0][0]=1;k.a[0][1]=1;k.a[1][0]=1;
  while(t!=0)
  {
    if(t&1){k=umn(k,m);}
    m=umn(m,m);
    t=t>>1;
  }
  return k;
}
int main()
{
  mat an;

  m.a[0][0]=1;
  m.a[0][1]=1;
  m.a[1][0]=1;
  m.a[1][1]=0;
  cin>>n>>mod;
  if(n==1||n==2)
  {
    cout<<1%mod<<endl;
    return 0;
  }
  an=povd(n-3);
  cout<<(an.a[0][0]+an.a[0][1])%mod<<endl;
  return 0;
}

