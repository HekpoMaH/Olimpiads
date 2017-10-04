#include <stdio.h>
int main(int argc, char *argv[])
{FILE *cf, *sf;
 long style,count,a,b,i;
 char *e,buf[16];
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
 if (!style) //First read integer is the count 
 {fscanf(sf,"%d",&count);
  if (fscanf(cf,"%d",&b)!=1 || b!=count)
  {fclose(sf);
   fclose(cf);
   printf("0\nCounts don't match.\n");
   return 0;
  }
 }
 else count=style;
 for (i=1;i<=count;i++)
 {fscanf(sf,"%d",&a);
  if (fscanf(cf,"%d",&b)!=1 || a!=b)
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
