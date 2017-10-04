#include<cstdio>
#include<cstdlib>

const int M=4000, N=4000;
int a[M+1][N+1], ax[M+1][N+1];
int b[N+1];
int m,n;
int u,v;


int main()
{

 scanf("%d%d%d%d",&m,&n,&u,&v);
 for(int i=0;i<m;i++)
 for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
 
 for(int i=0;i<m;i++)
 {
  int s=0;
  for(int j=0;j<v;j++) s+=a[i][j];
  ax[i][0]=s;
  for(int j=v;j<n;j++)
  { s = s + a[i][j] - a[i][j-v];
    ax[i][j-v+1]=s;
  }
 } 

 for(int j=0;j<=n-v;j++)
 for(int i=0;i<u;i++) b[j] += ax[i][j];
 
 int r=999999999;
 for(int j=0;j<=n-v;j++)
 { int s=b[j]; 
   if(abs(s)<r) r=abs(s);
  
   for(int i=u;i<m;i++)
   {
    s = s + ax[i][j]-ax[i-u][j];
    if(abs(s)<r) r=abs(s);

   }     
       
 } 
 
 printf("%d\n",r);
 
}
