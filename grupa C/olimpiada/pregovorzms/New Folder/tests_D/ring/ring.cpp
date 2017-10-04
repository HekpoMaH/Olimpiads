#include <stdio.h>
#define MAXN 1000001
int a[MAXN][2];
int main()
{
    int N,K;
    int i,j,t,u,v;
    
    scanf("%d %d",&N,&K);
    for(i=1;i<=N;i++) 
    {scanf("%d",&a[i][0]);a[i][1]=i+1;}
    a[N][1]=1;t=1;
    for(i=1;i<=N-1;i++)
    {
       for(j=2;j<K;j++) t=a[t][1];
       u=a[t][1]; //u - adres na iztriania
//printf("iztriva %d-ia\n",u);
       K=a[u][0]; //K-to na iztrivania
       a[t][1]=a[u][1];
       t=a[u][1];                   
    }
    printf("%d\n",t);   
}
