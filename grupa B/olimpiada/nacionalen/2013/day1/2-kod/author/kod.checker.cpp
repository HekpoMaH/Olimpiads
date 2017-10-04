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

int main(int argc, char *argv[])
{FILE *f;
 int points=0;
 char comp[2][2048],sol[2][2048];
 if (!(f = fopen(argv[3], "r")))      // solution file
 {printf("Cannot open solution.\n");
  return 0;
 }
 if (!freadline(string,f,sol[0],2047))
 {printf("Wrong solution file.\n");
  fclose(f);
  return 0;
 }
 if (!freadline(string,f,sol[1],2047))
 {printf("Wrong solution file.\n");
  fclose(f);
  return 0;
 }
 fclose(f);
 if (!(f = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  fclose(f);
  return 0;
 }
 if (!freadline(string,f,comp[0],2047))
 {printf("0\nNo output line 1.\n");
  fclose(f);
  return 0;
 }
 if (!strcmp(comp[0],sol[0])) points=1;else points=0;
 if (!freadline(string,f,comp[1],2047))
 {printf("%d\nNo output line 2.\n",points);
  fclose(f);
  return 0;
 }
 fclose(f);
 if (!strcmp(comp[1],sol[1])) points+=3;
 printf("%d\n",points);
 switch (points)
 {case 0:printf("Wrong answer\n");break;
  case 1:printf("First part solved\n");break;
  case 3:printf("Second part solved\n");break;
  case 4:printf("Correct\n");
 }
 return 0;
}
