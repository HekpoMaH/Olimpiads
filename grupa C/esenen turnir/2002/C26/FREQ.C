#include<stdio.h>
#include<string.h>


int i,n,j,a;
char max,A,p[255],buk2[26],buk[2][26];

int main(void){
scanf("%d /n",&n);

A='a';
for(i=0;i<=26-1;i++)
{buk[0][i]=A;A++;}

A='0';
for(i=0;i<=26-1;i++)
{buk[1][i]=A;}

A='0';
for(i=0;i<=26-1;i++)
{buk2[i]=A;}

for (i=0;i<=n-1;i++){

gets(p);

for (j=0;j<=strlen(p);j++)
   for (a=0;a<=25;a++)
     if (buk[0][a]==p[j]){buk2[a]++;}
for (j=0;j<=strlen(p);j++) if (buk[1][j]<buk2[j] )buk[1][j]=buk2[j];
}

max=buk[1][0];
for (i=0;i<=26;i++)
{if (buk[1][i]>max) max=buk[1][i];}
for (i=0;i<=26;i++)
{if (buk[1][i]==max){ printf("%c",buk[0][i]);printf(" ");printf("%c",max-2);break;}}



return 0;
}