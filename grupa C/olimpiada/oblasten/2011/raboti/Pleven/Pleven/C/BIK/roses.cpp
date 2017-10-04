#include<iostream>
using namespace std;

int m,n,k;
int i,j,p,q;
long long allsum,tempsum,sum;

int a[10001][10001];

int main()
{

   cin>>m>>n>>k;

   for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
      {
         cin>>a[i][j];
         allsum+=a[i][j];
      }

   for(i=1;i<=m-k+1;i++)
      for(j=1;j<=n-k+1;j++)
      {
         tempsum=0;
         for(p=i;p<i+k;p++)
            for(q=j;q<j+k;q++)
               tempsum+=a[p][q];
         if(tempsum>sum)
            sum=tempsum;
      }

   cout<<allsum-sum<<endl;

   return 0;
}
