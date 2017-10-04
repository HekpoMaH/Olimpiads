#include<iostream>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

long long m,n,i,j,i1,j1,k,s,s1,a[1001][1001],max1,b[1001][1001],l,s2;

int main()
{
    cin>>m>>n>>k;
    for(i=1;i<=m;i++)
    {
      for(j=1;j<=n;j++)
      {
        cin>>a[i][j];
        s=s+a[i][j];
        b[i][j]=b[i-1][j]+a[i][j];
      }
    }
    for(i=k;i<=m;i++)
    {
      for(j=k;j<=n;j++)
      {
        s1=0;
        s2=0;
        for(l=j-k+1;l<=j;l++)
        {
          s1=s1+b[i][l];
          s2=s2+b[i-k][l];
        }
        max1=max(s1-s2,max1);
      }
    }
    cout<<s-max1<<endl;
    return 0;
}
