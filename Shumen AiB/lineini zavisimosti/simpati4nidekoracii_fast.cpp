#include<iostream>
using namespace std;
struct mat
{
  unsigned long long a[100][100];
};
mat a;
unsigned long long n,m,mod;
bool check(int m1,int m2)
{
    int pos1,pos2,pos3,pos4;
    for(int j=0;j<m-1;j++)
    {
        pos1=m1&(1<<j);pos2=m1&(1<<(j+1));pos3=m2&(1<<j);pos4=m2&(1<<(j+1));
        if(pos1==0&&pos2==0&&pos3==0&&pos4==0){return false;}
        if(pos1!=0&&pos2!=0&&pos3!=0&&pos4!=0){return false;}
    }
    return true;
}
mat umn(mat m1,mat m2)
{
  mat c;
  unsigned long long s,sz=1<<m;
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

    cin>>n>>m>>mod;
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            if(check(i,j)==true)a.a[i][j]=1;
            //else a.a[i][j]=-1;
            //else cout<<i<<" "<<j<<endl;
        }
    }
    /*for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)cout<<a.a[i][j]<<" ";
        cout<<endl;
    }*/
    unsigned long long sum=0;
    povd(n-2,a);
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)sum+=a.a[i][j],sum%=mod;
    }
    cout<<sum%mod<<endl;
    return 0;
}