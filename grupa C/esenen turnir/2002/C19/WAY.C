#include<stdio.h>
int a1[45],a2[45],n,m,h,krai,path[46];
pat(int el,int nom)
{
int i,j;
if (path[m]==krai) return 0;
if (el==1)
  {
  for (i=0;i<h;i++)
    if (a1[i]==path[m]) {j=1;path[m]=a1[i];m++;path[m]=a2[i];pat(j,i);}  
    else if ((a2[i]==path[m])&&(i!=nom)) {j=0;path[m]=a2[i];m++;path[m]=a1[i];pat(j,i);}
  }
else
  {
  if (path[m]==krai) return 0;
  for (i=0;i<h;i++)
    if (a2[i]==path[m]) {j=0;path[m]=a2[i];m++;path[m]=a1[i];pat(j,i);}
    else if ((a1[i]==path[m])&&(i!=nom)) {j=1;path[m]=a1[i];m++;path[m]=a2[i];pat(j,i);}
  }
return 0;
}
int main()
{
int i,j,a,b,t,na4alo;
scanf("%d\n",&n);
switch (n)
  {
  case 3: m=3;
    break;
  case 4: m=6;
    break;
  case 5: m=10;
    break;
  case 6: m=15;
    break;
  case 7: m=21;
    break;
  case 8: m=28;
    break;
  case 9: m=36;
    break;
  case 10: m=45;
    break;
  }
if (n==1) {printf("1\n1");return 0;}
else if (n==2) 
       {
       scanf("%d %d %d",&a,&b,&t);
       if (t!=0) printf("2\n1 2");
       return 0;
       }
h=0;
for (i=0;i<m;i++)
  {
  scanf("%d %d %d\n",&a,&b,&t);
  if (t!=0) 
    {
    a1[h]=a;
    a2[h]=b;
    h++;
    }
  }
scanf("%d %d",&na4alo,&krai);
if (h==1) 
  {
  if ((a1[0]==na4alo)&&(a2[0]==krai))
    printf("2\n%d %d",a1,a2);
  else if ((a2[0]==na4alo)&&(a1[0]==krai))
	 {
	 printf("2\n%d %d",a2,a1);
	 }
  else printf("0");
  return 0;
  }
i=0;
path[0]=0;
m=0;
while ((path[m]!=krai)&&(i<h))
  {
  if (a1[i]==na4alo) {a=1;path[0]=a1[i];m=1;path[m]=a2[i];pat(a,i);}
    else if (a2[i]==na4alo) {a=0;path[0]=a2[i];m=1;path[m]=a1[i];pat(a,i);}
  i++;
  }
if (path[m]!=krai) {printf("0");return 0;}
printf("%d\n",m+1);
for (i=0;i<=m;i++)
  printf("%d ",path[i]);
return 0;
}