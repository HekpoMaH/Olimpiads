#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {integer, real, string} Type;
int freadline(Type t, FILE *f, char *b, int size)
{int i;
 char *e;
 b[0]=0;
 fgets(b,size,f);
 for (i=0;i<size&&b[i]&&b[i]!='\n';i++);
 b[i]=0;
 switch (t)
 {case string:return 1;
  case integer:{strtol(b,&e,10);
                return *b&&!*e;
               }
  case real:{strtod(b,&e);
             return *b&&!*e;
            }
 }
 return 0;
}
int isMono(const char *p,const char *q)
{for (;p<q;p++) if (*p!=*q) return 0;
 return 1;
}
int main(int argc, char *argv[])
{FILE *f;
 char buff[1024],*p,*q, *e;
 int minC,minC1;
 long long in,s=0,a;
 if (!(f = fopen(argv[1], "r")))      // input file
 {printf("Cannot open input.\n");
  return 0;
 }
 if (!freadline(string,f,buff,16))
 {printf("Wrong input.\n");
  fclose(f);
  return 0;
 }
 fclose(f);
 in=strtoll(buff,&p,10);
 if (*p || in<1 || in>=10000000000000000LL)
 {printf("Wrong input.\n");
  return 0;
 }
 if (!(f = fopen(argv[3], "r")))      // solution file
 {printf("Cannot open solution.\n");
  return 0;
 }
 if (!freadline(integer,f,buff,15))
 {printf("Wrong solution file.\n");
  fclose(f);
  return 0;
 }
 minC=strtol(buff,&p,10);
 fclose(f);
 if (!(f = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  fclose(f);
  return 0;
 }
 if (!freadline(integer,f,buff,31))
 {printf("0\nNo output line 1.\n");
  fclose(f);
  return 0;
 }
 minC1=strtol(buff,&p,10);
 if (minC1>minC)
 {printf("0\nCount not minimal.\n");
  fclose(f);
  return 0;
 }
 if (!freadline(string,f,buff,1023))
 {printf("0\nNo output line 2.\n");
  fclose(f);
  return 0;
 }
 fclose(f);
 p=buff;
 for (int i=0;i<minC;i++)
 {while (*p==' ' || *p=='\t') p++;
  q=strchr(p,' ');
  if (!q) q=&p[strlen(p)];
  if (p==q)
  {printf("0\nWrong addent count in line 2.\n");
   return 0;
  }
  if (!isMono(p,q-1))
  {printf("0\nAddent #%d in is not a mono.\n",i);
   return 0;
  }
  a=strtoll(p,&e,10);
  if (e!=q || a<1)
  {printf("0\nWrong addent #%d.\n",i);
   return 0;
  }
  s+=a;
  if (s>in)
  {printf("0\nThe sum of addents exceeds the input.\n");
   return 0;
  }
  p=q;
 }
 while (*p==' ' || *p=='\t') p++;
 if (*p)
 {printf("0\nAdditional output in line 2.\n");
  return 0;
 }
 if (s!=in)printf("0\nIncorrect sum.\n");
 else printf("2\nCorrect.\n");
 return 0;
}
