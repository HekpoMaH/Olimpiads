#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct {double x,y;} Point;
Point P[3],R[3],C[3];
double m;
int EofErr=0;
double Min(double a,double b)
{return (a<b)?a:b;
}
double Max(double a,double b)
{return (a>b)?a:b;
}
double dist(Point A,Point B)
{ return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double Area(Point A, Point B, Point C)
{ return 0.5*fabs((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
}
void inp1(FILE *f, Point *P)
{int i;
 for (i=0;i<3;i++)
  fscanf(f,"%lf %lf",&P[i].x,&P[i].y);
}
int inp2(FILE *f,Point *P)
{int i,er=0;
 char b[64],*p,*q;
 for (i=0;i<3;i++)
 {fgets(b,64,f);
  if (feof(f)) {EofErr=1; return 1;}
  b[strlen(b)-1]=0;
  p=strchr(b,'.');
  if (!p) er=1;
  else if (*(p+4)!=' ') er=1;
  p=strchr(p+1,'.');
  if (!p) er=1;
  else if (*(p+4)) er=1;
  P[i].x=strtod(b,&p);
  if (*p!=' ') er=1;
  P[i].y=strtod(p+1,&p);
  if (*p) er=1;
 }
 return er;
}
double distSum(Point A,Point B,Point C,
               Point A1,Point B1,Point C1)
{
  return dist(A,A1)+dist(B,B1)+dist(C,C1);
}
void solve(void)
{Point A,B,C;
 double st=10,m1,Ay=50,By=50;
 double S=Area(P[0],P[1],P[2]);
 int i,j,k;
 A.x=B.x=100;
 m=10000;
 for (int p=0;p<4;p++)
 {for (A.y=Ay-10*st;A.y<=100 && A.y<=Ay+100*st;A.y+=st)
   for (B.y=By+10*st;B.y>=0 && B.y>=By-100*st;B.y-=st)
    if (A.y>B.y)
    {C.x=100+2*S/(A.y-B.y);
     C.y=P[2].y;
     m1=distSum(P[0],P[1],P[2],A,B,C);
     if (m1<m){m=m1;Ay=A.y;By=B.y;R[0]=A;R[1]=B;R[2]=C;}
     m1=distSum(P[0],P[1],P[2],B,A,C);
     if (m1<m){m=m1;Ay=A.y;By=B.y;R[0]=B;R[1]=A;R[2]=C;}
     C.y=P[1].y;
     m1=distSum(P[0],P[1],P[2],A,C,B);
     if (m1<m){m=m1;Ay=A.y;By=B.y;R[0]=A;R[1]=C;R[2]=B;}
     m1=distSum(P[0],P[1],P[2],B,C,A);
     if (m1<m){m=m1;Ay=A.y;By=B.y;R[0]=B;R[1]=C;R[2]=A;}
     C.y=P[0].y;
     m1=distSum(P[0],P[1],P[2],C,A,B);
     if (m1<m){m=m1;Ay=A.y;By=B.y;R[0]=C;R[1]=A;R[2]=B;}
     m1=distSum(P[0],P[1],P[2],C,B,A);
     if (m1<m){m=m1;Ay=A.y;By=B.y;R[0]=C;R[1]=B;R[2]=A;}
    }
   st/=10;
 }
 m=distSum(P[0],P[1],P[2],R[0],R[1],R[2]);
}

int main(int argc, char **argv)
{FILE *fin, *fcomp;
 int i,formErr;
 double S,S1,m1;
 if (argc!=4)
 {printf("Argument error\n");
  return 0;
 }
 if (!(fin = fopen(argv[1], "r")))      // input file
 {printf("Cannot open input.\n");
  return 0;
 }
 inp1(fin,P);
 fclose(fin);
 if (!(fcomp = fopen(argv[2], "r")))    // competitor file
 {printf("0\nCannot open result.\n");
  return 0;
 }
 formErr=inp2(fcomp,C);
 fclose(fcomp);
 if (EofErr)
 {printf("0\nOutput file error.\n");
  return 0;
 }

 //Check the result in C
 for (i=0;i<3;i++)
  if (C[i].x<100 || C[i].y<0 || C[i].y>100)
  {printf("0\nCoordinates out of range.\n");
   return 0;
  }
 solve();
 S=Area(P[0],P[1],P[2]);
 S1=floor(10*Area(C[0],C[1],C[2])+0.5)/10;
 if (S!=S1)
 {printf("0\nDifferent area.\n");
  return 0;
 }
 m=floor(1000*m+0.5)/1000;
 m1= distSum(P[0],P[1],P[2],C[0],C[1],C[2]);
 m1=floor(1000*m1+0.5)/1000;
 if (m1<m)
 {printf("10\nCorrect.\n");
  return 0;
 }
 i=(int)floor(10*m*m*m*m/(m1*m1*m1*m1));
 printf("%d\n",i);
 if (i==10) printf("Correct.\n");
 else printf("Not optimal.\n");
 return 0;
}
