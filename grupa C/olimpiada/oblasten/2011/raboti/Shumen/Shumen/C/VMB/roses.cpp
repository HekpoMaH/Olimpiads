#include<cstdio>
using namespace std;
long long sum=0,o=0;
int main()
{
  int n,m,k,i,j,a[1100][1100],b[1100][1100],ma=0;
  scanf("%d%d%d",&m,&n,&k);
  for(i=0;i<m;i++)
  {
    o=0;
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
      sum+=a[i][j];
      o+=a[i][j];
      if(j+1>k)
      {
        b[i][j]=o-b[i][j-k];
        if(i>0)b[i][j]+=b[i-1][j-k];
        if(k<i+1)b[i][j]-=b[i-k][j-k];
      }
      else b[i][j]=o;
      if(i>0 && i+1<=k)b[i][j]+=b[i-1][j];
      else if(i>0)b[i][j]+=b[i-1][j]-b[i-k][j];
      if(b[i][j]>ma)
      {
        ma=b[i][j];
      }
    }
  }
  sum-=ma;
  printf("%lld\n",sum);
}