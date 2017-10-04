#include <stdio.h>
#include <string.h>
int freadstr(FILE *f, char *b, int bsize)
{int i;
 b[0]=0;
 fgets(b,bsize,f);
 if (!b) return 0;
 for (i=0;i<bsize&&b[i]&&b[i]!='\n';i++);
 b[i]=0;
 return 1;
}
int main(int argc, char *argv[])
{FILE *cf, *sf;
 long style,count,c,i;
 char *e,a[1024],b[1024];
 if (argc!=4)
 {printf("Argument error\n");
  return 0;
 }
 style=strtol(argv[1],&e,10); //first argument - check style 
 if (!(sf = fopen(argv[3], "r")))    // solution file
 {printf("Cannot open solution.\n");
  fclose(sf);
  return 0;
 }
 if (!(cf = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  return 0;
 }
 if (!style) //First read is an integer - the count 
 {fscanf(sf,"%d",&count);
  if (fscanf(cf,"%d",&c)!=1 || c!=count)
  {fclose(sf);
   fclose(cf);
   printf("0\nCounts don't match.\n");
   return 0;
  }
 }
 else count=style;
 for (i=1;i<=count;i++)
 {freadstr(sf,a,sizeof(a));
  if (!freadstr(cf,b,sizeof(b)) || strcmp(a,b))
  {fclose(sf);
   fclose(cf);
   printf("0\nLines %d mismatch.\n",i);
   return 0;
  }
 }
 fclose(sf);
 fclose(cf);
 printf("10\nCorrect solution\n");
 return 0;
}
