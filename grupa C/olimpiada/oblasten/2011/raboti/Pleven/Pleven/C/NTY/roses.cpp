#include<iostream>

using namespace std;
long long r[1000][1000],sum,max1;
int a[1000][1000];
int i,j,k,m,n,h,g;

int main()
{cin>>n>>m>>k;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{cin>>a[i][j];sum+=a[i][j];}

int col=0,colp=0;
for(g=0;g<=n-k;g++)
for(i=g;i<g+k;i++)
for(j=0;j<k;j++)
r[g][0]+=a[i][j];

for(i=0;i<=n-k;i++)
  for(j=1;j<=m-k;j++)
{col=0;colp=0;
  for(g=i;g<i+k;g++)
 {col+=a[g][j-1];
 colp+=a[g][j+k-1];
 }
 r[i][j]=r[i][j-1]-col+colp;

if(r[i][j]>max1)max1=r[i][j];
}




cout<<sum-max1<<endl;

return 0;
}
