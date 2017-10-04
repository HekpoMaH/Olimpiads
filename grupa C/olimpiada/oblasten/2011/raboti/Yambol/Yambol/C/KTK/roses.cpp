#include<iostream>
using namespace std;

short a[1000][1000];

int main()
{
   int i,j,m,k,n,r=0,s=0,p,sm=-1;
   cin>>n>>m>>k;
   for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
      {
         cin>>a[i][j];
         r=r+a[i][j];
      }   
   for(i=1;i<=n-k+1;i++)
   {
      s=0;
      for(p=i;p<=k+i-1;p++)
      {
         for(j=1;j<=k;j++)
         {
            s=s+a[p][j];
         }
      }
      if(s>sm)
      {
         sm=s;
      }
      for(j=2;j<=m-k+1;j++)
      {
         for(p=i;p<=k+i-1;p++)
         {
            s=s-a[p][j-1];
            s=s+a[p][j+k-1];
         }
         if(s>sm)
         {
             sm=s;
         }
      }
   }
   cout<<r-sm<<endl;
   return 0;
}
