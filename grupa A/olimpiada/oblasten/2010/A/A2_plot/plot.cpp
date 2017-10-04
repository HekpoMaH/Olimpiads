#include <iostream>
#include <math.h>
using namespace std;
typedef struct {double x,y;} Point;
Point P[3],R[3];
double m;
double dist(Point A,Point B)
{return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double Area(Point A, Point B, Point C)
{ return 0.5*fabs((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
}
void inp(void)
{for (int i=0;i<3;i++)
  cin>>P[i].x>>P[i].y;
}
void outp(Point A,Point B,Point C)
{cout.precision(3);
 cout<<fixed
     <<A.x<<' '<<A.y<<endl
     <<B.x<<' '<<B.y<<endl
     <<C.x<<' '<<C.y<<endl;
}
double distSum(Point A,Point B,Point C,
               Point A1,Point B1,Point C1)
{return dist(A,A1)+dist(B,B1)+dist(C,C1);
}

void solve(void)
{Point A,B,C;
 double st=10,m1,Ay=50,By=50;
 double S=Area(P[0],P[1],P[2]);
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
}

int main(void)
{
    inp();
    solve();
    outp(R[0],R[1],R[2]);
    return 0;
}
