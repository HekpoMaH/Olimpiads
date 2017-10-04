#include<cstdio>
#include<cstdlib>

const int M=4000, N=4000;
int a[M+1][N+1];
int m,n;
int u,v;


int main()
{

 scanf("%d%d%d%d",&m,&n,&u,&v);
 for(int i=0;i<m;i++)
 for(int j=0;j<n;j++) scanf("%d",&a[i][j]);

 int r=999999999;
 for(int i=0;i<=m-u;i++)
 for(int j=0;j<=n-v;j++)
 {
   int s=0;
   for(int i1=0;i1<u;i1++)
   for(int j1=0;j1<v;j1++)       
    s += a[i+i1][j+j1];
   if(abs(s)<r) r=abs(s);
 } 
 
 printf("%d\n",r);
 
 
}
