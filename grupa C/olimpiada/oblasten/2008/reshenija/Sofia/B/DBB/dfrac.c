#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long ull;
const ull dec_na[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,};
#define getinum(val,i) ((val/dec_na[i])%dec_na[i+1])
void minus(char* a,char* b,int n)
{
  static int i,na_um=0;
  for(i=n-1;i>-1;i--)
  {
    if(na_um)
    {
      if(a[i]=='0')
        a[i]='9';
      else
      {
        a[i]--;
        na_um=0;
      }
    }
    if(a[i]<b[i])
    {
      na_um=1;
      a[i]+=10;
    }
    a[i]-=(b[i]-'0');
  }
}
ull long_decre(char num[],int um,int n,int start)
{
  static int i;
   char *pf=(char*)malloc(sizeof(char)*(n+1));
  for(i=0;i<n;i++)
    pf[i]=getinum(start,n-1-i)+'0';
  minus(num,pf,n);
  for(i=0;i<n;i++)
    pf[i]=getinum(um,n-1-i)+'0';
  while(memcmp(pf,num,sizeof(char)*n)<0)
  {
    minus(num,pf,n);
  }
  free(pf);
  static ull res;
  sscanf(num,"%lu",&res);
  return res;
}
int main()
{
    ull a,b,tmp;
    int i,fc;
    char dec[1024];
    int ndec=0;
    int per_beg=-1,per_fin=0,dec_beg=0;
    scanf("%lu%lu",&a,&b);
    while(per_beg==-1)
    {
      tmp=a/b;
      fc=0;
      for(i=8;i>-1;i--)
        if(getinum(tmp,i)!=0)
        {
          fc=i;
          break;
        }
      tmp=getinum(tmp,fc)*dec_na[fc];
      a-=tmp*b;
      dec[ndec++]=getinum(tmp,fc)+'0';
      for(i=dec_beg;i<ndec-1&&dec_beg!=0;i++)
      {
        if(dec[ndec-1]==dec[i])
        {
          per_beg=i;
          per_fin=ndec-1;
          break;
        }
      }
      if(dec_beg==0&&a<b)
          dec_beg=ndec-1;
      while(a<b&&a!=0)
      {
        a*=10;
        }
    }
    int per_len=per_fin-per_beg;
    char* per=&dec[per_beg];
    for(i=1;(per_beg+i*per_len)<512;i++)
      memcpy(&per[i*per_len],per,per_len*sizeof(char));
    char k[19];
    int p;
    scanf("%s %d",k,&p);
    a=long_decre(k,per_fin-per_beg,strlen(k),per_beg-dec_beg);
    for(i=a+dec_beg-1;i<a+p+dec_beg-1;i++)
      printf("%c",dec[i]);
    printf("\n");
   // system("pause");
    return 0;
}
