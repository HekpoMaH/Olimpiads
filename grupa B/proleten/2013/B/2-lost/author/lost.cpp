#include <stdio.h>
#define MAXN 1000001
#define MAXH 2000003
#include <string.h>
int cards[MAXH][2],path[MAXN],K;
char ht[MAXH][64];
int hs,hf;

int hin(char* a)
{  int n=a[0],l=strlen(a),i=1;
   while(a[i]!='\0') n=(26*n+a[i++])%MAXH;
   while(ht[n][0]!='\0'&&strcmp(a,ht[n])!=0) n=(n+1)%MAXH;
   if(ht[n][0]=='\0') strcpy(ht[n],a);
   return n;
}

void from_start()
{  path[1]=cards[hs][0];
   for(int i=2;i<=K;i++)
   { if(cards[path[i-1]][0]!=path[i-2])
       path[i]=cards[path[i-1]][0];
     else
       if(cards[path[i-1]][1]!=-1)
          path[i]=cards[path[i-1]][1];
       else break;
    }
}

void from_end()
{  path[K-1]=cards[hf][0];
   for(int i=K-2;i>=0;i--)
   { if(cards[path[i+1]][0]!=path[i+2])
       path[i]=cards[path[i+1]][0];
     else
       if(cards[path[i+1]][1]!=-1)
          path[i]=cards[path[i+1]][1];
       else break;
    }
}

int main()
{  int c,i,j,ha,hb; char a[64],b[64],s[64],f[64];
   scanf("%d %s %s\n",&K,s,f);
   for(i=0;i<MAXH;i++) ht[i][0]='\0';
   for(i=0;i<MAXH;i++)cards[i][0]=cards[i][1]=-1;
   for(i=1;i<K;i++)
   {  scanf("%s %s\n",a,b);
      ha=hin(a);hb=hin(b);
      if(cards[ha][0]==-1) cards[ha][0]=hb;
      else cards[ha][1]=hb;
      if(cards[hb][0]==-1) cards[hb][0]=ha;
      else cards[hb][1]=ha;
   }
   hs=hin(s);hf=hin(f);
   c=1;
   if(cards[hs][0]==-1) c=0;
   else if(cards[hf][0]==-1) c=2;
   path[0]=hs;path[K]=hf;
   if(c!=0) from_start();
   if(c!=2) from_end();
   for(int i=0;i<=K;i++)
      printf("%s\n",ht[path[i]]);
}

