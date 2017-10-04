#include <stdio.h>

int a[1001][1001],h[1001][1001],v[1001][1001];
int main()
{
   int N,K,i,j,max=0,loc,p=0,q=0; 
   scanf("%d %d",&N,&K);
   for(i=1;i<=N;i++)
      for(j=1;j<=N;j++)
         scanf("%d",&a[i][j]);
   for(i=1;i<=N;i++)
   {
       h[i][N]=a[i][N];j=1;
       while(j<=K) {h[i][N-j]=a[i][N-j]+h[i][N-j+1];j++;}
       while(j<N) {h[i][N-j]=a[i][N-j]+h[i][N-j+1]-a[i][N-j+K+1];j++;}                
   }
   for(i=1;i<=N;i++)
   {
       v[N][i]=a[N][i];j=1;             
       while(j<=K) {v[N-j][i]=a[N-j][i]+v[N-j+1][i];j++;}
       while(j<N) {v[N-j][i]=a[N-j][i]+v[N-j+1][i]-a[N-j+K+1][i];j++;}                
   }                        
   for(i=1;i<=N;i++)
     for(j=1;j<=N;j++)
     {  loc=h[i][j]+v[i][j]-a[i][j];
        if(loc>max){max=loc;p=i;q=j;}
        }   
                           
   printf("%d %d\n",p,q);
   return 0;
}
