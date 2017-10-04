#include <stdio.h>
#include <string.h>
typedef struct
{int n;
 char c[64];
} Long;
Long game[4];
char sol[8];
int freadstr(FILE *f, char *b, int bsize)
{int i;
 b[0]=0;
 fgets(b,bsize,f);
 if (!b) return 0;
 for (i=0;i<bsize&&b[i]&&b[i]!='\n';i++);
 b[i]=0;
 return 1;
}
void mulDig(int d, Long *b)
{int carry=0,r,i;
 for (i=0;i<b->n;i++)
 {r=(b->c[i]-'0')*d+carry;
  b->c[i]=r%10+'0';
  carry=r/10;
 }
 if (carry) b->c[b->n++]=carry+'0';
}
void Div10(Long *b)
{if (b->n==1)b->c[0]='0';
 else memmove(b->c,&b->c[1],--b->n);
}
void Div2(Long *b)
{mulDig(5,b);
 Div10(b);
}
int cmp(const Long *a, const Long *b)
{int i;
 if (a->n<b->n) return -1;
 if (a->n>b->n) return 1;
 for (i=a->n-1;i>=0;i--)
 {if (a->c[i]<b->c[i]) return -1;
  if (a->c[i]>b->c[i]) return 1;
 }
 return 0;
}
void setLong(Long *a, char *s)
{int i,j;
 a->n=strlen(s);
 for (i=a->n-1,j=0;i>=0;i--,j++) 
  a->c[j]=s[i];
}
int inp(FILE *f)
{char b[64];
 int i;
 for (i=0;i<4;i++)
 {if (!freadstr(f,b,64)) return 0;
  setLong(&game[i],b);
 }
 return 1;
}
int check(Long g)
{Long start,end;
 int t1,t2,m=5;
 if (g.n==1 && g.c[0]=='0') return 1;
 setLong(&start,"10");
 do
 {end=start;
  mulDig(2,&end);
  t1=cmp(&g,&start);
  if (t1<0) return 0;
  t2=cmp(&g,&end);
  if (t1>=0 && t2<0) return 1;
  m^=1;
  mulDig(m,&start);
 } while (1);
}
int main(int argc, char *argv[])
{FILE *f;
 int i;
 if (argc!=4)
 {printf("Argument error\n");
  return 0;
 }
 if (!(f = fopen(argv[1], "r")))      // input file
 {printf("Cannot open input.\n");
  return 0;
 }
 if (!inp(f))
 {printf("Wrong input file.\n");
  fclose(f);
  return 0;
 }
 fclose(f);
/*
 if (!(f = fopen(argv[3], "r")))    // solution file
 {printf("Cannot open solution.\n");
  fclose(f);
  return 0;
 }
*/
 if (!(f = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  return 0;
 }
 if (!freadstr(f,sol,8))
 {printf("0\nWrong result file.\n");
  fclose(f);
  return 0;
 }
 fclose(f);
 if (strlen(sol)!=4)
 {printf("0\nWrong result file.\n");
  return 0;
 }
 for (i=0;i<4;i++)
  switch (sol[i])
  {case '0':{if (!check(game[i])){printf("0\nWrong move.\n");
                                  return 0;
                                 } 
             break;
            }
   case '1':{Div2(&game[i]);
             if (!check(game[i])){printf("0\nWrong move.\n");
                                  return 0;
                                 } 
             break;
            }
   case '2':{Div10(&game[i]);
             if (!check(game[i])){printf("0\nWrong move.\n");
                                  return 0;
                                 } 
             break;
            }
   default:{printf("0\nWrong character.\n");
            return 0;
           }
  }
 printf("10\nCorrect solution.\n");
 return 0;
}
