#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
long long i,j,z,t,n,m,k,s,ss,maxs,a[1111][1111];
int main()
{
  scanf ("%lld%lld%lld",&n,&m,&k);
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
    {
      scanf ("%lld",&a[i][j]);
      ss+=a[i][j];
      if (i>=k && j>=k)
      {
        s=0;
        for (z=i-k+1;z<=i;z++)
        {
          for (t=j-k+1;t<=j;t++)
          {
            s+=a[z][t];
          }
        }
        maxs=max(s,maxs);
      }
    }
  }
  cout<<ss-maxs<<endl;
  return 0;
}
/*
3 4 2
1 1 1 2
2 3 4 1
2 1 9 2
*/
//12
