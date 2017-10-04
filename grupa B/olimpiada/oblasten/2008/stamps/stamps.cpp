#include<cstdio>

int t[3001][3001];
int d[5001];
int S, N;

int main()
{
  
 scanf("%d%d",&S,&N);
 for(int i=1;i<=N;i++) scanf("%d",&d[i]); 
 
 int i=1; while(d[i]!=1) i++;
 int w=d[i]; d[i]=d[1]; d[1]=w;
 
 for(int j=1;j<=S;j++) t[1][j]=j;
 for(int i=1;i<=N;i++) {t[i][0]=0; t[i][1]=1;}

 for(int i=2;i<=N;i++)
 for(int j=2;j<=S;j++)
 {
   int jt=j;
   int v=t[i-1][jt];
   jt -= d[i];
   int c=0;
   while(jt>=0)
   {
     c++;
     if(v>t[i-1][jt]+c){v=t[i-1][jt]+c;}
     jt -= d[i];          
   }        
   t[i][j]=v;      
 }

 printf("%d\n",t[N][S]);
    
}
