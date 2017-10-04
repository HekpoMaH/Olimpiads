#include<iostream>
using namespace std;
long long n,x,y;
struct mat
{
  long long a[100][100];
};
long long mod;
mat m;
//mat mem[10000];
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
        s+=(m1.a[i][k]*m2.a[k][j])%mod;
      }
      c.a[i][j]=s;
    }
  }
  //cout<<c.a[0][0]<<" "<<c.a[0][1]<<endl;
  //cout<<c.a[1][0]<<" "<<c.a[1][1]<<endl;
  return c;

}
mat povd(long long t)
{
  mat k;
  bool y;
  k.a[0][0]=1;k.a[0][1]=1;k.a[1][0]=1;
  while(t!=0)
  {
    //cout<<y<<endl;
    if(t&1){k=umn(k,m);}
    m=umn(m,m);
    t=t>>1;
    //cout<<k.a[0][0]<<" "<<k.a[0][1]<<endl;
    //cout<<k.a[1][0]<<" "<<k.a[1][1]<<endl;
    //cout<<m.a[0][0]<<" "<<m.a[0][1]<<endl;
    //cout<<m.a[1][0]<<" "<<m.a[1][1]<<endl;
  }

  //cout<<k.a[0][0]<<" "<<k.a[0][1]<<endl;
  //cout<<k.a[1][0]<<" "<<k.a[1][1]<<endl;
  return k;
}
int main()
{
  mat an;

  m.a[0][0]=1;
  m.a[0][1]=1;
  m.a[1][0]=1;
  m.a[1][1]=0;
//  cin>>x;
//  for(int i=0;i<x;i++)
//  {
//    for(int j=0;j<x;j++)
//    {
//      cout<<m.a[i][j]<<" ";;
//    }
//    cout<<endl;
//  }
  cin>>n>>mod;
  if(n==1||n==2)
  {
    cout<<1%mod<<endl;
    return 0;
  }
  an=povd(n-3);
//  for(int i=0;i<2;i++)
//  {
//    for(int j=0;j<2;j++)
//    {
//      cout<<an.a[i][j]<<" ";;
//    }
//    cout<<endl;
//  }

  cout<<(an.a[0][0]+an.a[0][1])%mod<<endl;
  return 0;
}
