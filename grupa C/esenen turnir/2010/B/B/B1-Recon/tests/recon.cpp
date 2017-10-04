#include <stdio.h>
#define MAXN 1025

int N,a[MAXN][MAXN],gr[MAXN][MAXN],used[MAXN], chain[MAXN];
int fromch[MAXN][2],zarec[MAXN][3],recb,rece;

void rec()
{  int c,i,j,x,y,z,tmp,pos,from,to,l;
   from=zarec[recb][0];to=zarec[recb][1];l=zarec[recb++][2];
   chain[0]=from;  c=1; 
   for(i=1;i<=N;i++)
      if(i!=from&&i!=to)
         if(a[from][i]+a[i][to]==l) 
         {   chain[c++]=i; used[i]=1; }
   chain[c]=to;
   if(c==1)gr[from][to]=gr[to][from]=used[from]=used[to]=1;
   else  
   {  for(i=c-2;i>=0;i--)
         for(j=1;j<=i;j++)
         {  x=chain[j];y=chain[j+1];
            if(a[from][x]>a[from][y])
            { tmp=chain[j];chain[j]=chain[j+1];chain[j+1]=tmp;}
         }
      gr[from][chain[1]]=gr[chain[1]][from]=1;
      for(i=1;i<c-1;i++) 
      {  x=chain[i];y=chain[i+1];
         gr[x][y]=gr[y][x]=1;  
         used[x]=used[y]=1;
      }     
      gr[chain[c-1]][to]=gr[to][chain[c-1]]=1;
      used[from]=1; used[to]=1;
   } 
         
   for(i=0;i<=c;i++) fromch[i][0]=fromch[i][1]=0;
   for(pos=1;pos<=N;pos++)
   {  if(used[pos]) continue;
      else 
      {  x=a[from][pos];y=a[pos][to];
         z=(x+l-y)/2;i=0;
         while(a[from][chain[i]]!=z) i++;
         if((x+y-l)/2>fromch[i][1]) 
         {  fromch[i][1]=(x+y-l)/2;fromch[i][0]=pos; }
      }
   }
   for(i=0;i<=c;i++)
      if(fromch[i][1]!=0)
         {  zarec[++rece][0]=chain[i];
            zarec[rece][1]=fromch[i][0]; used[fromch[i][0]]=1;
            zarec[rece][2]=fromch[i][1];
         }  
   return;               
}  


int main()
{   int i,j,from,to,max=0;
    scanf("%d",&N); 
    for(i=1;i<N;i++)
    {  for(j=i+1;j<=N;j++)
       {  scanf("%d",&a[i][j]); a[j][i]=a[i][j];
          if(a[i][j]>max){max=a[i][j];from=i;to=j;} 
       }
    }   
    for(i=1;i<=N;i++) 
    {  used[i]=0;gr[i][0]=0;
       for(j=1;j<=N;j++) gr[i][j]=0;
    }
    recb=rece=0;
    zarec[0][0]=from;zarec[0][1]=to;zarec[0][2]=max;
    while (recb<=rece) rec();
    for(i=1;i<=N;i++)
    {   gr[i][0]=0;
        for(j=1;j<=N;j++) if(gr[i][j]) gr[i][0]++;
    }  
    for(i=1;i<=N;i++)
    {   printf("%d",gr[i][0]);
        for(j=1;j<=N;j++)
           if(gr[i][j]) printf(" %d",j);
        printf("\n");
    }
    return 0;   
}     
