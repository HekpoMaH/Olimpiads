#include<iostream>
using namespace std;
long long nod(long long x,long long y)
{
     while(x!=y)
     if(x>y)x=x-y;
     else y=y-x;
     return x;
     }
int main()
{
    int m,i,j,k;
    long long x,y;
    cin>>k>>m;
    int a[21][21];
     long long b[21][21];
    a[1][1]=1; b[1][1]=1;
    for (i=2;i<=k;i++)
    {a[i][1]=1; b[i][1]=i;
      for (j=2;j<=i;j++)
       {a[i][j]=1; 
        x=b[i-1][j-1]*b[i][j-1];
       y=b[i][j-1]-b[i-1][j-1];
        b[i][j]=x/nod(x,y);
       } 
     }
        
        cout<< a[k][m]<<endl;
        cout<<"-"<<endl;
        cout<<b[k][m];
        return 0;
}
