#include<iostream>
using namespace std;
long long n,x,y,b;
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
void povd(long long t,mat &k)
{
    k.a[0][0]=b;k.a[0][1]=1;
    k.a[1][0]=0;k.a[1][1]=1;
    m=k;
  while(t!=0)
  {
    if(t&1){k=umn(k,m);}
    m=umn(m,m);
    t=t>>1;
  }
}
int main()
{
  mat an,a;
  cin>>n>>b>>mod;
  an.a[0][0]=b;an.a[0][1]=1;
  an.a[1][0]=0;an.a[1][1]=1;
  a.a[0][0]=1;a.a[1][0]=1;
  povd(n-1,an);
  //cout<<an.a[0][0]<<endl;
  an=umn(an,a);
  cout<<an.a[0][0]%mod<<endl;
  return 0;
}

