#include<iostream>

using namespace std;
int a[101][101];
int used[101][101];
int m,n,r,k;
int i,j,d;
long long sum;

void path(int ii,int jj,int k)
{ if (jj==0)jj=m;
used[ii][jj]=1;
int i,j,kk;
  for(kk=1;kk<=k;kk++)
  {for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
  if(used[i][j]==kk)
{if(j<m){used[i][j+1]=kk+1;}
if(j>1 ){used[i][j-1]=kk+1;}
if(i<n ){used[i+1][j]=kk+1;}
if(i>1 ){used[i-1][j]=kk+1;}
}
}
}
int main()
{cin>>n>>m>>r>>k;
d=1;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
{a[i][j]=d;d++;}
if(r%m==0) path(r/m,r%m,k);
else path(r/m+1,r%m,k);

for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(used[i][j]==k+1)sum+=a[i][j];

cout<<sum<<endl;

return 0;
}