#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int eqDoubles(double d1, double d2)
{double d=fabs(d1-d2);
 if (d<=0.001) return 4;
 if (d<=0.01) return 3;
 if (d<=0.1) return 2;
 if (d<=1) return 1;
 return 0;
}

int main(int argc, char *argv[])
{FILE *f;
 double comp,sol;
 int points=0,linef;
 char buf[32], *e;
 if (!(f = fopen(argv[3], "r")))      // solution file
 {printf("Cannot open solution.\n");
  return 0;
 }
 if (!freadline(real,f,buf,30))
 {printf("Wrong solution file.\n");
  fclose(f);
  return 0;
 }
 sol=strtod(buf, &e);
 fclose(f);
 if (!(f = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  fclose(f);
  return 0;
 }
 linef=freadline(real,f,buf,30);
 fclose(f);
 if (!linef)
 {printf("0\nIncorrect output format.\n");
  return 0;
 }
 if (strchr(buf,0)-strchr(buf,'.')!=4)
 {printf("0\nIncorrect output format.\n");
  return 0;
 }
 comp=strtod(buf, &e);
 points=eqDoubles(sol,comp);
 printf("%d\n",points);
 switch (points)
 {case 0:printf("Too far away\n");break;
  case 1:printf("Precision too low\n");break;
  case 2:printf("Low precision\n");break;
  case 3:printf("Almost there\n");break;
  case 4:printf("Correct\n");
 }
 return 0;
}
