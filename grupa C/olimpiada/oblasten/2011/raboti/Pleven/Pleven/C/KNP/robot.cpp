#include<iostream>
using namespace std;
long a[101][101],sum,i,j,l,l1,l2=1,m,n,r,k,i1,j1,sum1;
int main()
{
  cin>>m>>n>>r>>k;
  for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
   {
    a[i][j]=l2;l2++;
    if(a[i][j]==r) {i1=i;j1=j;}
   }
   i=i1;j=j1;
int   k1=k;
  for(l=k;l>=1;l--)
  {l1=k-l;
  sum+=a[i-l1][j-l]+a[i+l][j-l1]+a[i+l1][j+l]+a[i-l][j+l1];
  cout<<l1<<" "<<l<<endl;
  cout<<a[i-l1][j-l]<<" "<<a[i+l][j-l1]<<" "<<a[i+l1][j+l]<<" "<<a[i-l1][j+l]<<endl;
  }k1-=2;
  while(k1>0)
  {
   sum+=a[i-k1][j]+a[i+k1][j]+a[i][j-k1]+a[i][j+k1];
   cout<<a[i-k1][j]<<" "<<a[i+k1][j]<<" "<<a[i][j-k1]<<" "<<a[i][j+k1]<<endl;
   k1-=2;
  }
  if(k%2==0)
   cout<<sum+r<<endl;
   else cout<<sum<<endl;

return 0;
}