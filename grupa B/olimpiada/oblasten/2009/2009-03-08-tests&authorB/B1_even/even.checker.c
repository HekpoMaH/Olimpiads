#include <stdio.h>
#include <string.h>
long long makell(char *p,char **end)
{long long l=0;
 char *q=p;
 if (*p=='-' || *p=='+') q++;
 while (*q>='0' && *q<='9')
 {l=(long long)10*l+*q-'0';
  q++;
 }
 if (*p=='-') l=-l;
 *end=q;
 return l;
}
typedef enum {false,true} bool;
int freadint(FILE *f, char *b, int bsize, int cnt, int ressize, void *res)
{union {char c;
	    short i;
        long l;
        long long ll;} r;
 int i,p;
 char *e;
 b[0]=0;
 fgets(b,bsize,f);
 if (!b) return 0;
 for (i=0;i<bsize&&b[i]&&b[i]!='\n';i++);
 b[i]=' ';
 b[i+1]=0;
 p=0;
 for (i=0;i<cnt;i++)
 {while (b[p]==' '||b[p]=='\t') p++;
  r.ll=makell(&b[p],&e);
  if (*e!=' ' && *e!='\t') return 0;
  switch (ressize)
  {case sizeof(char):((char *)res)[i]=r.c; break;
   case sizeof(short):((short *)res)[i]=r.i; break;
   case sizeof(long):((long *)res)[i]=r.l; break;
   case sizeof(long long):((long long *)res)[i]=r.ll; break;
   default: return 0;
  }
  p=e-b+1;
 }
 return 1;
}

bool isLosing(long long n, long long k)
{long long t;
 if (k&1) t=n%(2*(k+1));
 else t=n%(k+2); 
 return t==1;
}

int main(int argc, char *argv[])
{FILE *f;
 long long k;
 char buf[256];
 long long res[10];
 int p=0,i,j;
 if (argc!=4)
 {printf("Argument error\n");
  return 0;
 }
 if (!(f = fopen(argv[1], "r")))      // input file
 {printf("Cannot open input.\n");
  return 0;
 } 
 if (!freadint(f,buf,sizeof(buf),1,sizeof(long long),&k))
 {printf("Bad input\n");
  fclose(f);
  return 0;
 }
 fclose(f);
 if (!(f = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  return 0;
 }
 if (!freadint(f,buf,sizeof(buf),10,sizeof(long long),res))
 {printf("0\nWrong output line.\n");
  fclose(f);
  return 0;
 }
 fclose(f);
 for (i=0;i<10;i++)
 {for (j=0;j<i;j++) if (res[i]==res[j]) break;
  if (j==i && res[i]>3 && isLosing(res[i],k)) p++;
 }
 printf("%d\n",p);
 switch (p)
 {case 0: printf("No correct value\n"); break;
  case 10: printf("Correct solution\n"); break;
  default: printf("Some correct values\n");
 }
 return 0;
}
