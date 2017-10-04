/*
TASK: trade
LANG: C++
*/
#include <stdio.h>
#include <math.h>

   int N, gr[100001][3]; double a[100001],b[100001][2];
   int queue[100001],used[100001],qb,qe,x,y;

int main()
{
   int i,j,k; double s;
   scanf("%d",&N);
   for(i=1;i<=N;i++) {gr[i][0]=used[i]=0;}
   for(i=1;i<=N;i++)
   {
      scanf("%d %d %lf",&j,&k,&s);
      b[j][gr[j][0]]=s;gr[j][++gr[j][0]]=k;
      b[k][gr[k][0]]=s;gr[k][++gr[k][0]]=j;                 
   }
//   for(i=1;i<=N;i++) printf("%d %d %lf %lf\n",gr[i][1],gr[i][2],b[i][0],b[i][1]);
   queue[1]=1;used[1]=1;
   queue[0]=gr[1][1];used[gr[1][1]]=1;
   a[gr[1][1]]=b[1][0];
   qb=qe=1;
   while(qb<=qe)
   {
      x=queue[qb++];
      y=gr[x][1];
      if(!used[y]){queue[++qe]=y;used[y]=1;a[x]=b[x][0];} 
      y=gr[x][2];
      if(!used[y]){queue[++qe]=y;used[y]=1;a[x]=b[x][1];}            
   }
   y=queue[qe];
   if(gr[y][1]==queue[qe-1]) a[y]=b[y][1];
   else a[y]=b[y][0];
//   for(i=0;i<=qe;i++) printf("%d %lf\n",queue[i],a[queue[i]]);
   if(N%2==1)
   {
      s=0;
      for(i=0;i<N;i++) if(i%2) s-=a[queue[i]]; else s+=a[queue[i]];
//      printf("s=%lf\n",s);
      b[queue[0]][0]=s;
      for(i=1;i<=qe;i++)
      { x=queue[i-1];y=queue[i];b[y][0]=2*a[x]-b[x][0]; }
      for(i=1;i<=N;i++) 
      {printf("%.2lf",b[i][0]);
       if(i!=N) printf(" "); else printf("\n");
       }
   } 
   else
   {
      s=0;
      for(i=0;i<N-1;i++) if(i%2) s-=a[queue[i]]; else s+=a[queue[i]];
//      printf("2s=%lf 2bn=%lf\n",2.*s,2.*a[queue[qe]]);
      if(fabs(s-a[queue[qe]])<0.000001) printf("too many\n");
      else printf("impossible\n");
/*      b[queue[0]][0]=s;
      for(i=1;i<=qe;i++)
      { x=queue[i-1];y=queue[i];b[y][0]=2*a[x]-b[x][0]; }
      for(i=1;i<=N;i++) printf("%lf\n",b[i][0]);
*/      
   }
   return 0;
}
