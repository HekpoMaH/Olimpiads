#include<iostream>
using namespace std;
struct mat
{
  long long a[100][100];
};
mat a;
long long n,m,help;
long long mod=602214179;
void create(long long mask,long long pos)
{
    if(pos<0){a.a[mask][help]=1;return;}
    if(mask&(1<<pos))help*=2,create(mask,pos-1),help/=2;
    else
    {
        if(pos>0&&!(mask&(1<<pos))&&!(mask&(1<<(pos-1))))
        {
            help*=4;create(mask,pos-2);help/=4;
        }
        if(!(mask&(1<<pos)))help=help*2+1,create(mask,pos-1),help/=2;
    }
}
mat umn(mat m1,mat m2)
{
  mat c;
  long long s,sz=1<<m;
  for(int i=0;i<sz;i++)
  {
    for(int j=0;j<sz;j++)
    {
      s=0;
      for(int k=0;k<sz;k++)
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
    k=a;
   mat m=k;
  while(t!=0)
  {
    if(t&1){k=umn(k,m);}
    m=umn(m,m);
    t=t>>1;
  }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<(1<<m);i++)
    {
        help=0;
        create(i,m-1);
    }
    mat start;start.a[0][0]=1;
    povd(n-1,a);
    //for(int i=0;i<(1<<m);i++)for(int j=1;j<(1<<m);j++)if(a.a[i][j]!=0)cout<<"D"<<endl;
    a=umn(a,start);//for(int i=0;i<(1<<m);i++)for(int j=1;j<(1<<m);j++)if(a.a[i][j]!=0)cout<<"D"<<endl;
    cout<<a.a[0][0]<<endl;
    return 0;
}
