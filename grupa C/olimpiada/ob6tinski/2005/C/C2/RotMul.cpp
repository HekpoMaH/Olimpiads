#include <stdio.h>
#include <string.h>

char DigToChar(int d)
{return '0'+d;}

int Less(char *a,char *b)
{while (*a=='0') a++;
 while (*b=='0') b++;
 if (strlen(a)!=strlen(b)) return strlen(a)<strlen(b);
 return strcmp(a,b)<0;
}

char *RotMul(int times, char *res)
{int last,rem,c,i;
 char s[256];
 *res=0;
 for (last=1;last<=9;last++)
 {*s=0;
  i=0;
  rem=last%times;
  c=last/times;
  if (c>0) {do
            {s[i++]=DigToChar(c);
             c+=10*rem;
             rem=c%times;
             c/=times;
            }while (rem||c!=last);
            if (times>1) s[i++]=DigToChar(last);
            s[i]=0;
            if (!*res||Less(s,res)) strcpy(res,s);
           }
 }
 return res;
}

int main(void)
{int K;
 char r[256];
 scanf("%d",&K);
 if (K>9) printf("NO\n");
 else printf("%s\n",RotMul(K,r));
 return 1;
}

