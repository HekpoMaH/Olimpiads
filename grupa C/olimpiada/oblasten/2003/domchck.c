#include <stdio.h>
#include <math.h>
#define MAXN 16
void main()
{
    FILE *in,*ou;
    int N,BN,co[MAXN]={0},dom[MAXN][2];
    int i,j,minco[MAXN]={0},min,x=0;
    char s[MAXN];

    in=fopen("domino.inp","r");
    ou=fopen("domino.out","r");
    fscanf(in,"%d",&N);
    for(i=1;i<=N;i++)
    {
       fscanf(in,"%d %d",dom[i],dom[i]+1);
       x+=(dom[i][0]-dom[i][1]);
       min=abs(x);
    }

    BN=(1<<N)-1;
    for(i=1;i<=BN;i++)
    {
      if(co[1]==0) co[1]=1;
      else
      {
        j=1;while(co[j]==1){co[j]=0;j++;} co[j]=1;
      }
      x=0;
      for(j=1;j<=N;j++)
      {
        if(co[j]==0) x+=(dom[j][0]-dom[j][1]);
        else x+=(dom[j][1]-dom[j][0]);
      }
      if(abs(x)<min)
      {
        min=abs(x);
        for(j=1;j<=N;j++) minco[j]=co[j];
      }
    }
    fscanf(ou,"%s",s);
    for(j=1;j<=N;j++)
       if(s[j-1]=='0') minco[j]=0;
       else minco[j]=1;
    x=0;
    for(j=1;j<=N;j++)
    {
       if(minco[j]==0) x+=(dom[j][0]-dom[j][1]);
       else x+=(dom[j][1]-dom[j][0]);
    }
    if(abs(x)==min) printf("OK\n");
    else printf("Not correct!!!\n");
}
