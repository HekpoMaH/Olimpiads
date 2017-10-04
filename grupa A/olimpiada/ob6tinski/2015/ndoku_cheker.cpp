#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {integer, string} Type;
typedef enum {false,true} bool;
unsigned long N;
char ULeft[16][16];
char a[36][40];
char b[1024];
bool c[36];
long strToUL(const char *buf,const char **end,int radix)
{unsigned long S=0;
 const char *e=buf;
 while (*e)
 {int v;
  if (*e<'0' || *e>'z') {*end=e;return S;}
  if (*e<='9') v=*e-'0';
  else if (*e<='Z') {v=*e-'A';
                     if (v<0) {*end=e;return S;}
                     v+=10;
                     }
       else {v=*e-'a';
             if (v<0) {*end=e;return S;}
             v+=10;
            }
  if (v>=radix) {*end=e;return S;}
  S=S*radix+v;
  e++;
 }
 *end=e;
 return S;   
}
int freadline(Type t, FILE *f, char *b, int size,unsigned long *r)
{int i;
 const char *e;
 b[0]=0;
 if (!fgets(b,size,f)) return 0;
 for (i=0;i<size-1&&b[i]&&b[i]!='\n';i++);
 b[i]=0;
 switch (t)
 {case string:return i;
  case integer:{*r=strToUL(b,&e,10);
                return *b&&!*e;
               }
 }
 return 0;
}
int cmp(const void *a,const void *b)
{return *(const char *)a-*(const char *)b;
}

int main(int cnt,char **argv)
{FILE *f;
 unsigned long i,j,q,x,y,k,l;
 char *p;
 if (!(f = fopen(argv[1], "r")))  // input file
 {printf("Cannot open input.\n");
  return 0;
 }
 if (!freadline(integer,f,b,16,&N))
 {printf("Wrong input.\n");
  fclose(f);
  return 0;
 }
 if (N<2 || N>6)
 {printf("Wrong number in input line 1.\n");
  fclose(f);
  return 0;
 }
 for (i=0;i<N;i++)
 {l=freadline(string,f,ULeft[i],16,NULL);
  if (l!=(int)N)
  {printf("%ld symbols in input line %ld. Should be %ld.\n",l,i+2,N);
   fclose(f);
   return 0;
  }
 }
 fclose(f);     //Input file correctly read
 for (i=0;i<N;i++) strcpy(&b[i*N],ULeft[i]);    
 qsort(b,N*N,1,cmp);
 for (i=1;i<N*N;i++) 
 {if (b[i]==b[i-1])
  {printf("Repeating symbol %c in input.\n",b[i]);
   return 0;
  }
  if (b[i]<'0' || (b[i]>'9' && (b[i]<'A' || b[i]>'Z')))
  {printf("Incorrect input symbol %c.\n",b[i]);
   return 0;
  }
 }
 //Input correct
 if (!(f = fopen(argv[2], "r")))    //competitor file
 {printf("0\nCannot open result.\n");
  return 0;
 }
 for (i=0;i<N*N;i++)
 {l=freadline(string,f,a[i],40,NULL);
  if (l!=(int)(N*N))
  {printf("0\n%ld symbols in output line %ld. Should be %ld\n",l,i+1,N*N);
   return 0;    
  }
 }
 for (i=0;i<N;i++)
  if (memcmp(ULeft[i],a[i],N))
  {printf("0\nUpper left squares do not match\n");
   return 0;    
  }
 //Check lines
 for (i=0;i<N*N;i++)
 {for (j=0;j<N*N;j++) c[j]=false;
  for (j=0;j<N*N;j++)
  {p=(char *)bsearch(&a[i][j],b,N*N,1,cmp);
   if (!p) {printf("0\nWrong symbol %c in output line %ld\n",a[i][j],i+1);
            return 0;
           }
   q=p-b;
   if (c[q]){printf("0\nRepeating symbol %c in output line %ld\n",a[i][j],i+1);
             return 0;
            }
   c[q]=true;
  }
 }     
 //Check columns
 for (i=0;i<N*N;i++)
 {for (j=0;j<N*N;j++) c[j]=false;
  for (j=0;j<N*N;j++)
  {p=(char *)bsearch(&a[j][i],b,N*N,1,cmp);
   q=p-b;
   if (c[q]){printf("0\nRepeating symbol %c in output column %ld\n",a[j][i],i+1);
             return 0;
            }
   c[q]=true;
  }
 }
 //Check squares
 for (x=0;x<N*N;x+=N) //the square tops (x,y)
  for (y=0;y<N*N;y+=N)
  {for (j=0;j<N*N;j++) c[j]=false;
   for (k=0;k<N;k++)
    for (l=0;l<N;l++)
    {char *p=(char *)bsearch(&a[x+k][y+l],b,N*N,1,cmp);
     q=p-b;
     if (c[q]){printf("0\nRepeating symbol %c in output square starting at (%ld, %ld)\n",a[x+k][y+l],x+1,y+1);
               return 0;
              }
     c[q]=true;
    }
  }
 printf("10\nCorrect\n");
 return 0;
}
