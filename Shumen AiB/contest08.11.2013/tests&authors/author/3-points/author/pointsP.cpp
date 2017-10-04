#include <cstdio>
#include <algorithm>
using namespace std;
char r[1024],c[1024];
int lstx[1024][1024];
int main()
{ int N,i,j,col,row,x,y,startx,endx;
  for (i=0;i<1024;i++) lstx[i][0]=r[i]=c[i]=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
  {  scanf("%d %d",&x,&y);
     lstx[y][++lstx[y][0]]=x;
  }

  //nachalo i kray za X
  i=0;while(i<1024&&lstx[i][0]==0) i++;
  startx=endx=i;i++;
  while(i<1024) {if(lstx[i][0]!=0) endx=i; i++;}
  //spisaci na y-koordinatite po redove
  for(i=startx;i<=endx;i++)
  {  if(lstx[i][0]) sort(lstx[i]+1,lstx[i]+lstx[i][0]+1); }

  for(row=startx;row<=endx;row++)
  {  for(j=1;j<=lstx[row][0];j++)
     {  col=lstx[row][j];
        if (r[row]==1 || c[col]==1)
        { printf("%d %d R\n",col,row); r[row]--; c[col]--; continue; }
        printf("%d %d B\n",col,row); r[row]++; c[col]++;
     }
  }
  return 0;
}
