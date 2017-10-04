#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int n,q,f[3005][503],f1,f2,f3,f4,f5,f6;
int main()
{
  cin>>n>>q;
  for(int i=0;i<=n;i++)for(int j=0;j<=q;j++)f[i][j]=0;
  for(int i=1;i<=6;i++)f[1][i]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=q;j++)
    {
      f1=0;f2=0;f3=0;f4=0;f5=0;f6=0;
      if(j-1>=0)f1=f[i-1][j-1];
      if(j-2>=0)f2=f[i-1][j-2];
      if(j-3>=0)f3=f[i-1][j-3];
      if(j-4>=0)f4=f[i-1][j-4];
      if(j-5>=0)f5=f[i-1][j-5];
      if(j-6>=0)f6=f[i-1][j-6];
      f[i][j]=f1+f2+f3+f4+f5+f6;
    }
  }
  int all=1;
  for(int i=1;i<=n;i++)all*=6;
  //cout<<setiosflags(ios::fixed)<<setprecision(5)<<v<<endl;
  cout<<(double)f[n][q]/all<<endl;
  //printf("%.5lf",v);
  return 0;
}
