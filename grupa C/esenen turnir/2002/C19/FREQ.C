#include<stdio.h>

int main()
{
int n,a[10000],g,br,m,i,j,maxi,max;
char c[256],h,b[10000];
scanf("%d\n",&n);
for (g=0;g<n;g++)
  {
  m=0;
  a[g]=0;
  h='a';
  while (h!='\n')
    {
    scanf("%c",&h);
    if ((h!=' ')&&(h!='\n'))
      {
      c[m]=h;
      m++;
      }
    c[m]=0;
    }
  for (i=0;i<m-1;i++)
    {
    br=0;
    if (c[i]!='1')
      for (j=i+1;j<m;j++)
	 if (c[i]==c[j]) {br++;c[j]='1';}
    if (br+1>a[g]) {a[g]=br+1;b[g]=c[i];}
    }
 	 }
max=a[0];
maxi=0;
for (i=1;i<n;i++) 
  if (max<a[i]) {max=a[i];maxi=i;}
printf("%c %d",b[maxi],max);
return 0;
}