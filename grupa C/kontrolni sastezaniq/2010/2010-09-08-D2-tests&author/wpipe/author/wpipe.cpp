#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

struct Point {
  int x,y;
};
struct Ots{
     Point A,B;
     bool h;
};

struct Oblast{
     int br;
     Ots T [21];
};


    int N;
    Oblast Tr[101];
    int dx,dy,dKw;
    int kX,kY;
    int xN,yN;
    int r[101][101];

void Nac () {
int i,j;

      cin>>xN>>yN;
      cin>>N;

      for (i=1;i<=N; i++)
       {
        cin>>Tr[i].br;
        for (j=1; j<=Tr[i].br; j++)
         {
          cin>>Tr[i].T[j].A.x>>Tr[i].T[j].A.y>>Tr[i].T[j].B.x>>Tr[i].T[j].B.y;
          Tr[i].T[j].h=(Tr[i].T[j].A.y==Tr[i].T[j].B.y);
         }
       }
}

int Razst(Point t1, Point t2)
{
    return (abs(t1.x-t2.x)+abs(t1.y-t2.y));
}

int Minim(int a, int b)
{
    a=abs(a);
    b=abs(b);
    if (a<b) 
     return a;
     else
     return b;
}

int PytT(Ots t1, Ots t2)
{
  int  d;
  bool Fl;

    Fl=false;
    d=0;
    if (t1.h && t2.h)      
     {
      if (((t2.A.x<=t1.A.x) && (t1.A.x<=t2.B.x)) ||
         ((t2.B.x<=t1.A.x) && (t1.A.x<=t2.A.x)) ||
         ((t1.A.x<=t2.A.x) && (t2.A.x<=t1.B.x)) ||
         ((t1.B.x<=t2.A.x) && (t2.A.x<=t1.A.x)) ||

         ((t2.A.x<=t1.B.x) && (t1.B.x<=t2.B.x)) ||
         ((t2.B.x<=t1.B.x) && (t1.B.x<=t2.A.x)) ||
         ((t1.A.x<=t2.B.x) && (t2.B.x<=t1.B.x)) ||
         ((t1.B.x<=t2.B.x) && (t2.B.x<=t1.A.x))) 
          {
           d=abs(t1.A.y-t2.A.y);
           Fl=true;
          }
     }
    if (!(t1.h) && !(t2.h))
     {
      if (((t2.A.y<=t1.A.y) && (t1.A.y<=t2.B.y)) ||
         ((t2.B.y<=t1.A.y) && (t1.A.y<=t2.A.y)) ||
         ((t1.A.y<=t2.A.y) && (t2.A.y<=t1.B.y)) ||
         ((t1.B.y<=t2.A.y) && (t2.A.y<=t1.A.y)) ||

         ((t2.A.y<=t1.B.y) && (t1.B.y<=t2.B.y)) ||
         ((t2.B.y<=t1.B.y) && (t1.B.y<=t2.A.y)) ||
         ((t1.A.y<=t2.B.y) && (t2.B.y<=t1.B.y)) ||
         ((t1.B.y<=t2.B.y) && (t2.B.y<=t1.A.y))) 
          {
           d=abs(t1.A.x-t2.A.x);
           Fl=true;
          }
     }
    if (t1.h && !(t2.h)) 
     {
      if (((t2.A.y<=t1.A.y) && (t1.A.y<=t2.B.y)) ||
         ((t2.B.y<=t1.A.y) && (t1.A.y<=t2.A.y))) 
          {
           d=Minim(t1.A.x-t2.A.x,t1.B.x-t2.A.x);
           Fl=true;
          } 
          else
       if ((((t1.A.x<=t2.A.x) && (t2.A.x<=t1.B.x)) ||
          ((t1.B.x<=t2.A.x) && (t2.A.x<=t1.A.x))))
           {
            d=Minim(t2.A.y-t1.A.y,t2.B.y-t1.A.y);
            Fl=true;
           }
     }
    if (!(t1.h) && t2.h)
     {
      if (((t1.A.y<=t2.A.y) && (t2.A.y<=t1.B.y)) ||
         ((t1.B.y<=t2.A.y) && (t2.A.y<=t1.A.y)))
          {
           d=Minim(t2.A.x-t1.A.x,t2.B.x-t1.A.x);
           Fl=true;
          }
          else
       if (((t2.A.x<=t1.A.x) && (t1.A.x<=t2.B.x)) ||
          ((t2.B.x<=t1.A.x) && (t1.A.x<=t2.A.x)))
           {
            d=Minim(t1.A.y-t2.A.y,t1.B.y-t2.A.y);
            Fl=true;
           }

     }
    if (!Fl)
     {
      d=Minim(Razst(t1.A,t2.A),Razst(t1.A,t2.B));
      d=Minim(d,Razst(t1.B,t2.A));
      d=Minim(d,Razst(t1.B,t2.B));
     }

    return d;
}


int MinPyt (int n1, int n2)
{
   int d,i,j,dMin;

   d=30000;
   for (i=1; i<=Tr[n1].br; i++)
    for (j=1; j<=Tr[n2].br; j++)
     {
      dMin=PytT(Tr[n1].T[i],Tr[n2].T[j]);
      if (d>dMin) d=dMin;
     }
   return d;
}

void Path ()
{
    int L[101],H[101];
    int  i,v1,v2,N1,v0,Min1,v00;
    int Otg;

    N1=N+2;
    v1=N+1; v2=N+2;
    for (i=1; i<=N1; i++)
     {
      L[i]=20000;
      H[i]=0;
     }
    L[v1]=0; H[v1]=1000;
    v0=v1;  v00=0;
    while (v0!=v2) 
    {
     Min1=20000;
     for (i=1;i<=N1;i++)
      if (H[i]==0)
       {
        if (L[i]>L[v0]+r[i][v0])
         L[i]=L[v0]+r[i][v0];
        if (Min1>L[i])
         {
          v00=i;
          Min1=L[i];
         }
       }
     H[v00]=v0;
     v0=v00;
    }
    
    
    Otg=L[v2];
    cout<<Otg<<endl;

}

void Razst () {
int i,j,N1;

    N1=N+1;
    Tr[N1].br=1;
    Tr[N1].T[1].A.x=0;
    Tr[N1].T[1].A.y=0;
    Tr[N1].T[1].B.x=0;
    Tr[N1].T[1].B.y=0;
    Tr[N1].T[1].h=true;
    N1=N1+1;
    Tr[N1].br=1;
    Tr[N1].T[1].A.x=xN;
    Tr[N1].T[1].A.y=yN;
    Tr[N1].T[1].B.x=xN;
    Tr[N1].T[1].B.y=yN;
    Tr[N1].T[1].h=true;

    for (i=1; i<=N1-1; i++)
     for (j=i+1; j<=N1;j++)
      {
       r[i][j]=MinPyt(i,j);
       r[j][i]=r[i][j];
      }
      
    Path ();
}


int main()
{
 Nac ();
 Razst ();   
// system("pause");
 return 0;
}

