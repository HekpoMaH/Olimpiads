#include<iostream>
using namespace std;
int n,k,a[3000]/*,d[5000][5000]*/;
int main()
{
    int i,j,p;
          cin>>n>>k;
          for(i=0;i<k;i++)
           cin>>a[i];
         /* sort(a,a+k);
          for(i=0;i<=n;i++)
           {d[0][i]=1;d[i][i]=1;}
          for(i=1;i<=n;i++)
           for(j=1;j<i;j++)
            d[i][j]=d[i-1][j];
          for(i=1;i<=n;i++)
           for(j=1;j<i;j++)
            for(p=0;p<k;p++)
           {
            d[i][j]+=d[i-1][j-a[p]];
           }
          for(i=0;i<=n;i++)
          { for(j=0;j<=i;j++)
            cout<<d[i][j]<<' ';
           cout<<endl; }*/
           cout<<n/k<<endl;
          return 0;
}
