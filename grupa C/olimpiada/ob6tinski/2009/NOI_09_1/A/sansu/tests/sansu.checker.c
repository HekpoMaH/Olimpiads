#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef enum {false,true} bool;
short s0[8]={377,715,3785,4069,4173,5299,5421,5681};
short s1[72]={403,455,481,611,637,689,1079,1209,1365,1911,2067,2119,2483,2665,2873,
3185,3471,3575,3787,3791,3839,3841,3849,3855,3913,3939,3947,3953,3961,3963,4057,
4071,4095,4147,4169,4179,4219,4223,4227,4231,4303,4329,4771,4927,4979,5243,5245,
5253,5259,5297,5311,5369,5415,5419,5447,5499,5513,5519,5527,5529,5603,5623,5627,
5631,5635,5655,5675,5685,5733,6123,6175,6331};
short s2[172]={5635,5655,5675,5685,5733,6123,6175,6331,1025,1131,1157,1203,1207,
1313,1361,1371,1391,1411,1415,1419,1423,1443,1807,1833,1841,1847,1855,1857,1885,
1905,1909,2011,2041,2063,2073,2145,2321,2509,2537,2639,2653,2667,2717,2743,2815,
2819,2823,2827,2867,2877,2899,3023,3137,3139,3147,3153,3237,3341,3393,3419,3467,
3477,3569,3579,3627,3713,3751,3761,3777,3795,3799,3801,3823,3829,3845,3853,3865,
3911,3935,3949,3957,3989,3993,4025,4041,4055,4061,4065,4083,4145,4153,4163,4165,
4177,4195,4197,4217,4233,4245,4257,4275,4297,4305,4323,4603,4667,4693,4745,4759,
4773,4811,4817,4825,4827,4901,4973,4983,5005,5035,5155,5201,5207,5219,5249,5257,
5279,5303,5307,5313,5323,5331,5363,5371,5393,5397,5405,5407,5411,5435,5451,5487,
5515,5523,5553,5565,5571,5605,5621,5637,5653,5677,5689,5691,5727,5761,5763,5779,
5787,5945,5947,5955,5961,6007,6097,6117,6121,6163,6177,6201,6357,6409,6435};
short s4[96]={887,889,935,941,959,961,967,1043,1115,1169,1265,1291,1321,1331,1343,
1347,1399,1435,1583,1589,1591,1609,1615,1661,1663,1745,1771,1799,1817,1877,1921,
1927,1929,1993,2083,2137,2339,2345,2401,2417,2501,2573,2609,2725,2777,2779,2805,
2857,2987,2993,2995,3071,3103,3125,3129,3221,3377,3427,3437,3449,3507,3539,3593,
3597,3609,3619,4507,4523,4579,4585,4685,4715,4793,4795,4845,4909,4963,5053,5873,
5875,5881,5927,5977,5979,6031,6089,6133,6139,6185,6211,6213,6219,6249,6265,6349,6427};
short s5[4]={881,1669,3453,6141};
int a[3][3],b[3][3],compSol[3][3],sol[3][3]={0};
int d;
char buf[64];
bool found=false;
int compMin,theMin,minCnt;
int freadint(FILE *f, char *b, int bsize, int cnt, int ressize, void *res)
{union {char c;
	    int i;
        long l;} r;
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
  r.l=strtol(&b[p],&e,10);
  if (*e!=' ' && *e!='\t') return 0;
  switch (ressize)
  {case 1:((char *)res)[i]=r.c; break;
   case 2:((short *)res)[i]=r.i; break;
   case 4:((long *)res)[i]=r.l; break;
   default: return 0;
  }
  p=e-b+1;
 }
 return 1;
}

bool check(int a[3][3])
{int r,c,s;
 for (r=0;r<2;r++)
 {s=0;
  for (c=0;c<3;c++) s+=a[r][c];
  if (s%3) return false;
 }
 for (c=0;c<2;c++)
 {s=0;
  for (r=0;r<3;r++) s+=a[r][c];
  if (s%3) return false;
 }
 return true;
}

short Code(int a[3][3])
{int s=0,r,c;
 for (r=0;r<3;r++)
  for (c=0;c<3;c++) s=3*s+(a[r][c]);
 return s;
}

int cmp(const void *a, const void *b)
{return *(short *)a-*(short *)b;
}

void swap(int *a,int *b)
{int c=*a;
 *a=*b;
 *b=c;
}

int dist(int a[3][3],int b[3][3])
{int d=0,ra,ca,rb,cb,t;
 for (ra=0;ra<3;ra++) for (ca=0;ca<3;ca++)
 {t=a[ra][ca];
  for (rb=0;rb<3;rb++) 
   {for (cb=0;cb<3 && b[rb][cb]!=t;cb++);
    if (cb<3) break;
   }
  d+=(abs(ra-rb)+abs(ca-cb)); 
 }
 return d;
}

void go(int cnt,int d, int pr, int pc)
{int r,c,d1;
 if (found) return;
 if (cnt>compMin) return;
 if (!d && !((compMin-cnt)&1)) {found=true; return;}
 if (cnt==compMin)
 {found=!memcmp(a,compSol,sizeof(a));
  return;
 }
 for (r=0;r<3;r++)
  for (c=0;c<2;c++) if (c!=pc || r!=pr)
  {swap(&b[r][c],&b[r][c+1]);
   d1=dist(b,compSol);
   if (d1<=d) {swap(&a[r][c],&a[r][c+1]);
               go(cnt+1,d1,r,c);
               swap(&a[r][c],&a[r][c+1]);
               if (found) return;
              } 
   swap(&b[r][c],&b[r][c+1]);
  } 
 for (c=0;c<3;c++) if (c!=pc || r!=pr)
  for (r=0;r<2;r++)
  {swap(&b[r][c],&b[r+1][c]);
   d1=dist(b,compSol);
   if (d1<=d) {swap(&a[r][c],&a[r+1][c]);
               go(cnt+1,d1,r,c);
               swap(&a[r][c],&a[r+1][c]);
               if (found) return;
              }
   swap(&b[r][c],&b[r+1][c]);
  } 
}

void show(int sol[3][3])
{int r,c;
 for (r=0;r<3;r++)
 {for (c=0;c<3;c++) printf("%d ",sol[r][c]);
  printf("\n");
 }
}

int permParity(int a[3][3])
{int p=0,r,c,t;
 int b[9];
 for (t=0,r=0;r<3;r++) for (c=0;c<3;c++) b[t++]=a[r][c];
 for (r=0;r<8;r++) for (c=r+1;c<9;c++) if (b[r]>b[c]) p^=1;
 return p;
}

int main(int argc, char *argv[])
{FILE *f;
 int i,j,p1,p2;
 short cd;
 char dig[10]={0};
 if (argc!=4)
 {printf("Argument error\n");
  return 0;
 }
 if (!(f = fopen(argv[1], "r")))      // input file
 {printf("Cannot open input.\n");
  return 0;
 }
 for (i=0;i<3;i++) if (!freadint(f,buf,sizeof(buf),3,sizeof(int),a[i]))
                   {printf("Bad input, line # %d\n",i+1);
                    fclose(f);
                    return 0;
                   }
 fclose(f);

//printf("Input:\n");
//show(a);

/* if (!(f = fopen(argv[3], "r")))    // solution file - not needed here
 {printf("Cannot open solution.\n");
  fclose(f);
  return 0;
 }
*/
 if (!(f = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  return 0;
 }
 if (!freadint(f,buf,sizeof(buf),1,sizeof(int),&compMin))
 {printf("0\nWrong first line.\n");
  fclose(f);
  return 0;
 }
 for (i=0;i<3;i++) if (!freadint(f,buf,sizeof(buf),3,sizeof(int),&compSol[i]))
                   {printf("0\nBad result, line # %d\n",i+1);
                    fclose(f);
                    return 0;
                   }
 fclose(f);

//printf("Result: %d\n",compMin);
//show(compSol);

//Are all digits included?
 for (i=0;i<3;i++) for (j=0;j<3;j++)
 {if (dig[compSol[i][j]]) {printf("0\nRepeating digit: %d\n",compSol[i][j]);
                           return 0;
                          } 
  dig[compSol[i][j]]=1;
 }
// Check for sansu
 if (!check(compSol)) {printf("0\nNot sansu\n");
                       return 0;
                      }  
 if (compMin>22) {printf("0\nToo many moves\n");
                  return 0;
                 }  
//Do compMin moves lead to compSol sansu?
 p1=permParity(a);
 p2=permParity(compSol);
 if (p1==p2 && (compMin&1) || p1!=p2 && !(compMin&1))
 {printf("0\nNo %d moves lead to this sansu\n",compMin);
  return 0;
 }
 d=dist(a,compSol);
//printf("Dist = %d\n",d); 
 memmove(b,a,sizeof(a));
 go(0,d,-1,-1);
 if (!found)
 {printf("0\nNo %d moves lead to this sansu\n",compMin);
  return 0;
 }
//Find the actual min.
 for (i=2;i>=0;i--) for (j=2;j>=0;j--) a[i][j]=(a[i][j]+9-a[0][0])%3;
//printf("Reduced:\n");
//show(a);
 cd=Code(a);
//printf("Code :%d\n",cd);
 if (bsearch(&cd,s0,8,sizeof(short),cmp)) theMin=0;
 else if (bsearch(&cd,s1,72,sizeof(short),cmp)) theMin=1;
 else if (bsearch(&cd,s2,172,sizeof(short),cmp)) theMin=2;
 else if (bsearch(&cd,s4,96,sizeof(short),cmp)) theMin=4;
 else if (bsearch(&cd,s5,4,sizeof(short),cmp)) theMin=5;
 else theMin=3;
//printf("The min :%d\n",theMin);
//compMin=20;
 if (theMin==compMin)
 {printf("10\nCorrect solution\n");
  return 0;
 }
 printf("%0.f\nCorrect but not minimal\n",round(10-(compMin-theMin)*10.0/(22-theMin)));
 return 0;
}
