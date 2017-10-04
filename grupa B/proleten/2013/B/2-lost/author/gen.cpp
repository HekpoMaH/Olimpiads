#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXN 1000001
#define MAXH 2000003
int perm[MAXN],K,y;
char names[MAXN][64];
char ht[MAXH][64];

int hin(char* a)
{  int n=a[0],i=1;
   while(a[i]!='\0') n=(26*n+a[i++])%MAXH;
   if(ht[n][0]=='\0') {strcpy(ht[n],a);return 0;}
   while(ht[n][0]!='\0')
   { //printf("1 %d\n",n);
     if(strcmp(a,ht[n])==0) return 1; else n=(n+1)%MAXH;
   }
   strcpy(ht[n],a);return 0;
}

void gen_name(int i)
{
  int len;
  do
  {  len=rand()%62+1;
     for(int j=0;j<len;j++) names[i][j]='a'+rand()%26;
     names[i][len]='\0'; //printf("2 %d\n",i);
  } while(hin(names[i]));

}

int main(int argc, char* argv[])
{  int i;
   srand((unsigned)time(NULL));
   for(i=0;i<MAXH;i++) ht[i][0]='\0';
//   scanf("%d %d",&K,&y);
   K=atoi(argv[1]); y=atoi(argv[2]);
   for(i=0;i<=K;i++) gen_name(i);
   for(i=0;i<=K;i++) perm[i]=i;
   for(i=0;i<K-1;i++)
   {
      int x=rand()%(K-i);
      int tmp=perm[i];perm[i]=perm[i+x];perm[i+x]=tmp;
   }
   int z,z1;
   printf("%d %s %s\n",K,names[0],names[K]);
   if(y==0) z1=0;
   else if(y==2) z1=K-1;
   else z1=rand()%(K-3)+2;
   for(i=0;i<K;i++)
     if(perm[i]!=z1)
     {  z=rand()%2;
        if(z)printf("%s %s\n",names[perm[i]],names[perm[i]+1]);
        else printf("%s %s\n",names[perm[i]+1],names[perm[i]]);
     }
}
