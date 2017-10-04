#include <stdio.h>
#include <stdlib.h>
long blank=0;
#define null_long(val) memcpy(&val,&blank,sizeof(long))
inline long GetIBit(long from,int i)
{
  return (from & (1<<i))>>i;
}
typedef struct
{
  long matr[30];
}plate;
int n;
int la_cmp(const void* a,const void* b)
{
  return memcmp( ((plate*)a)->matr,((plate*)b)->matr,sizeof(long)*n);
}
void rot(plate*ne,plate old)
{
  static int i,j;
  for(i=0,null_long(ne->matr[i]);i<n;i++,null_long(ne->matr[i]))
    for(j=0;j<n;j++)
      ne->matr[i] |= (GetIBit(old.matr[n-1-j],i)<<j);
}
void flip(plate*ne,plate old)
{
  static int i,j;
  for(i=0,null_long(ne->matr[i]);i<n;i++,null_long(ne->matr[i]))
    for(j=0;j<n;j++)
      ne->matr[i]|=(GetIBit(old.matr[n-1-i],j)<<j);
}
plate all[1000];
plate tmp[8];
char buf[32];
int m;
int i,j,k;
int max_ne=0;
int main()
{
    scanf("%d%d",&m,&n);
    //scanf("%s",buf);
    for(k=0;k<m;k++)
    {
      null_long(tmp[0].matr[0]);
      for(i=0;i<n;i++)
      {
        null_long(tmp[0].matr[i]);
        scanf("%s",buf);
        for(j=0;j<n;j++)
          tmp[0].matr[i]|=(buf[j]=='1')<<j;
      }
      rot(&tmp[2],tmp[0]);
      rot(&tmp[4],tmp[2]);
      rot(&tmp[6],tmp[4]);
      flip(&tmp[1],tmp[0]);
      flip(&tmp[3],tmp[2]);
      flip(&tmp[5],tmp[4]);
      flip(&tmp[7],tmp[6]);
      qsort(tmp,8,sizeof(plate),la_cmp);
      for(i=0;i<max_ne&&la_cmp(&all[i],&tmp[0]);i++);
      if(i==max_ne)
        memcpy(&all[max_ne++],tmp,sizeof(plate));
    }
    printf("%d\n",max_ne);
    //system("pause");
    return 0;
}
