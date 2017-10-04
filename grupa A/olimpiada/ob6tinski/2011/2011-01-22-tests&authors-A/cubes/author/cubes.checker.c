#include <stdio.h>
#include <string.h>

#define NN 1024
char inBuf[2][NN],solBuf[2][NN],resBuf[2][NN];

void freadLine(FILE *f, char *b, int size)
{int i;
 b[0]=0;
 fgets(b,size,f);
 for (i=0;i<size&&b[i]&&b[i]!='\n';i++);
 b[i--]=0;
 while (i>=0&&b[i]==' ') b[i--]=0;
}

int checkNumber(char *s)
{int i=0;
 while (s[i]>='0'&&s[i]<='9') i++;
 if (!s[i]) return 0;
 return i;
}

int chkLine(char *s)
{int c=0,i=0;
 c=checkNumber(s);
 if (!c) return 0;
 while (s[c]==' ') s[c++]=0;
 if (checkNumber(&s[c])) return 0;
 return c;
}

int cmp(const char *s1,const char *s2)
{int l1=strlen(s1),l2=strlen(s2);
 if (l1>l2) return 1;
 if (l1<l2) return -1;
 return strcmp(s1,s2);
}

char *muldig(const char *s,char d,char *res)
{int l=strlen(s)-1,c=0,i,r;
 res[l+2]=0;
 for (i=l;i>=0;i--)
 {r=(s[i]-'0')*d+c;
  c=r/10;
  r=r%10;
  res[i+1]=r+'0';
 }
 if (c) *res=c+'0';
 else res++;
 return res;
}

char *add(const char *a,const char *b, char *res)
{int cr=0,r,i,j,la=strlen(a)-1,lb=strlen(b)-1,k=(la>lb)?la+1:lb+1;
 res[k+1]=0;
 for (i=la,j=lb;i>=0||j>=0;i--,j--,k--)
 {if (i>=0)r=a[i]-'0'; else r=0;
  if (j>=0) r+=(b[j]-'0');
  r+=cr;
  if (r>9) {r-=10;cr=1;}
  else cr=0;
  res[k]=r+'0';
 }
 if (cr) *res='1';
 else res++;
 return res;
}

char *mul(const char *a,const char *b, char *res)
{int i,j,t,lb=strlen(b)-1;
 *res='0';
 res[1]=0;
 char r[NN],*p;
 for (i=lb;i>=0;i--)
 {p=muldig(a,b[i]-'0',r);
  t=strlen(p);
  for(j=0;j<lb-i;j++) p[t+j]='0';
  p[t+j]=0;
  res=add(res,p,res);
 }
 return res;
}

char *deg3(const char *a, char *res)
{char b[NN],*p;
 p=mul(a,a,b);
 return mul(p,a,res);
}

char *sub(const char *a,const char *b, char *res)
{int bo=0,r,i,j,la=strlen(a)-1,lb=strlen(b)-1;
 res[la+1]=0;
 for (i=la,j=lb;i>=0;i--,j--)
 {if (j>=0) r=a[i]-b[j]-bo;
  else r=a[i]-'0'-bo;
  if (r<0) {r+=10;bo=1;}
  else bo=0;
  res[i]=r+'0';
 }
 while (*res=='0') res++;
 if (!*res) res--;
 return res;
}

int main(int argc, char **argv)
{FILE *fin, *fcomp, *fsol;
 int t;
 char r[NN],r1[NN],r2[NN],*p,*q;
 if (argc!=4)
 {printf("Argument error\n");
  return 0;
 }
 if (!(fin = fopen(argv[1], "r")))  // input file
 {printf("Cannot open input.\n");
  return 0;
 }
 freadLine(fin,inBuf[0],NN);
 freadLine(fin,inBuf[1],NN);
 fclose(fin);
 if (checkNumber(inBuf[0]))
 {printf("Wrong input line 1.\n");
  return 0;
 }
 if (checkNumber(inBuf[1]))
 {printf("Wrong input line 2.\n");
  return 0;
 }
 if (!(fsol = fopen(argv[3], "r")))  // solution file
 {printf("Cannot open solution.\n");
  return 0;
 }
 freadLine(fsol,solBuf[0],NN);
 freadLine(fsol,solBuf[1],NN);
 fclose(fsol);
 if (!(fcomp = fopen(argv[2], "r"))) // competitor file
 {printf("0\nCannot open result.\n");
  return 0;
 }
 freadLine(fcomp,resBuf[0],NN);
 freadLine(fcomp,resBuf[1],NN);
 fclose(fcomp);
 t=chkLine(resBuf[0]);
 if (!t)
 {if  (strcmp(resBuf[0],solBuf[0]))
   {printf("0\nIncorrect answer 1.\n");
    return 0;
   }
 }
 else
 {
  p=resBuf[0];
  q=&resBuf[0][t];
  p=deg3(p,r1);
  q=deg3(q,r2);
  if (cmp(p,q)<0 || cmp(inBuf[0],sub(p,q,r)))
  {printf("0\nIncorrect answer 1.\n");
   return 0;
  }
 }
 t=chkLine(resBuf[1]);
 if (!t)
 {if  (strcmp(resBuf[1],solBuf[1]))
   {printf("0\nIncorrect answer 2.\n");
    return 0;
   }
 }
 else
 {
  p=resBuf[1];
  q=&resBuf[1][t];
  p=deg3(p,r1);
  q=deg3(q,r2);
  if (cmp(p,q)<0 || cmp(inBuf[1],sub(p,q,r)))
  {printf("0\nIncorrect answer 2.\n");
   return 0;
  }
 }
 printf("10\nCorrect.\n");
 return 0;
}

