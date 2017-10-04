#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;
#define randomize() (srand(time(0)))
#define random(x) (rand() % x)
#define rnd(lo,hi) ((lo) + (random(((hi)-(lo)+1))))
typedef struct
{int X,Y;
} Point;
long twiceArea(Point A,Point B,Point C)
{return abs((B.X-A.X)*(C.Y-A.Y)-(C.X-A.X)*(B.Y-A.Y));
}
int solve(Point *P)
{int sABC,sABD,sACD,sBCD,m;
 sABC=twiceArea(P[0],P[1],P[2]);
 sABD=twiceArea(P[0],P[1],P[3]);
 sACD=twiceArea(P[0],P[2],P[3]);
 sBCD=twiceArea(P[1],P[2],P[3]);
 switch (!sABC + !sABD + !sACD + !sBCD)
 {case 1:return 2;
  case 2:return 1;
  case 4:return 0;
  default:
  {m=sABC;
   if (sABD>m) m=sABD;
   if (sACD>m) m=sACD;
   if (sBCD>m) m=sBCD;
   if (2*m==sABC+sABD+sACD+sBCD) return 3;
   return 4;
  }
 }
}
void make3Tests(int lo, int hi,int *rs,Point P[3][4])
{int r[3],t[3],i,j;
 sort(rs,&rs[3]);
 do
 {for (i=0;i<3;i++)
  {for (j=0;j<4;j++)
   {P[i][j].X=rnd(lo,hi);
    P[i][j].Y=rnd(lo,hi);
   }
   r[i]=solve(P[i]);
  }
  memcpy(t,r,sizeof(r));
  sort(t,&t[3]);
 }while (t[0]!=rs[0] || t[1]!=rs[1] || t[2]!=rs[2]);
  memcpy(rs,r,sizeof(r));
}
void showPoints(ostream &os, const Point *P)
{for (int j=0;j<4;j++) os<<P[j].X<<' '<<P[j].Y<<endl;
}
void makeFiles(ostream &o1,ostream &o2,const Point *P,int r)
{showPoints(o1,P);
 o2<<r<<endl;
}
void ThreeTests(int TripletNo,int lo,int hi,int *rs)
{Point P[3][4];
 char name1[16]="dots.000.in";
 char name2[16]="dots.000.sol";
 make3Tests(lo,hi,rs,P);
 for (int i=0;i<3;i++)
 {int t=3*TripletNo+i+1;
  name1[6]='0'+t/10;
  name1[7]='0'+t%10;
  name2[6]='0'+t/10;
  name2[7]='0'+t%10;
  ofstream f1(name1);
  ofstream f2(name2);
  makeFiles(f1,f2,P[i],rs[i]);
 }
}
int main()
{int rs[3];
// randomize();
 cout<<1<<' ';
 rs[0]=0;rs[1]=1;rs[2]=4;
 ThreeTests(0,1,10,rs);
 cout<<2<<' ';
 rs[0]=1;rs[1]=2;rs[2]=3;
 ThreeTests(1,-10,10,rs);
 cout<<3<<' ';
 rs[0]=2;rs[1]=2;rs[2]=4;
 ThreeTests(2,0,30,rs);
 cout<<4<<' ';
 rs[0]=0;rs[1]=3;rs[2]=4;
 ThreeTests(3,-30,30,rs);
 cout<<5<<' ';
 rs[0]=1;rs[1]=3;rs[2]=3;
 ThreeTests(4,0,50,rs);
 cout<<6<<' ';
 rs[0]=1;rs[1]=1;rs[2]=4;
 ThreeTests(5,-50,50,rs);
 cout<<7<<' ';
 rs[0]=2;rs[1]=3;rs[2]=4;
 ThreeTests(6,0,80,rs);
 cout<<8<<' ';
 rs[0]=0;rs[1]=4;rs[2]=3;
 ThreeTests(7,-80,80,rs);
 cout<<9<<' ';
 rs[0]=0;rs[1]=1;rs[2]=4;
 ThreeTests(8,0,100,rs);
 cout<<10<<' ';
 rs[0]=1;rs[1]=3;rs[2]=4;
 ThreeTests(9,-100,100,rs);
 cout<<endl<<"Ready\n";
 return 0;
}
