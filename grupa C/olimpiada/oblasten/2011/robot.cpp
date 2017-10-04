#include<cmath>
#include<iostream>
using namespace std;
long long a[109][109],m,n,k,r,br,nai,naj;
int main()
{
  cin>>m>>n>>r>>k;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      br++;
      a[i][j]=br;
      if(br==r)
      {
        nai=i;
        naj=j;
      }
    }
  }
  long long ra=0,sum=0;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      ra=abs((double)nai-(double)i)+abs((double)naj-(double)j);
      if(ra%2==k%2&&ra<=k)sum+=a[i][j];
    }
  }
  cout<<sum<<endl;
  return 0;
}
