#include <iostream>
#include <cstring>
using namespace std;
int const MAX=30;
int const MM=MAX*MAX+1;
int a[MAX][MAX];
int M,N;
typedef struct {int row,col,dist;} Pos;
Pos PQue[4*MM];
void Wave(int r,int c)
{char b[4];
 if (a[r][c]) return;
 int st=0,fin=1;
 Pos p,q;
 p.row=r;p.col=c;p.dist=1;
 PQue[0]=p;
 while (st<fin)
 {p=PQue[st++];
  if (a[p.row][p.col] && (a[p.row][p.col]<=p.dist || a[p.row][p.col]==MM)) continue;
  a[p.row][p.col]=p.dist;
  q=p;
  q.dist=p.dist+1;
  if (p.col!=0 && p.col!= M-1 && p.row>1) {q.row=p.row-1;PQue[fin++]=q;q.row=p.row;}
  if (p.col!=0 && p.col!= M-1 && p.row<N-2) {q.row=p.row+1;PQue[fin++]=q;q.row=p.row;}
  if (p.row!=0 && p.row!=N-1 && p.col>1) {q.col=p.col-1;PQue[fin++]=q;q.col=p.col;}
  if (p.row!=0 && p.row!=N-1 && p.col<M-2) {q.col=p.col+1;PQue[fin++]=q;q.col=p.col;}
 }
}
int secLevCats()
{int c=0;
 for(int i=1;i<M-1;i++) if (a[1][i]==MM && a[0][i]!=MM) {a[1][i]=a[0][i]=MM+1;c++;}
 for(int i=1;i<M-1;i++) if (a[N-2][i]==MM && a[N-1][i]!=MM) {a[N-2][i]=a[N-1][i]=MM+1;c++;}
 for(int i=1;i<N-1;i++) if (a[i][1]==MM && a[i][0]!=MM) {a[i][1]=a[i][0]=MM+1;c++;}
 for(int i=1;i<N-1;i++) if (a[i][M-2]==MM && a[i][M-1]!=MM) {a[i][M-2]=a[i][M-1]=MM+1;c++;}
 return c;
}
int remDeadlocks()
{int c=0;
 if (a[1][1]==MM+1){if (a[0][1]==1) {c++; a[0][1]=MM+1;}
                    if (a[1][0]==1) {c++; a[1][0]=MM+1;}
                   }
 if (a[1][M-2]==MM+1){if (a[0][M-2]==1) {c++; a[0][M-2]=MM+1;}
                      if (a[1][M-1]==1) {c++; a[1][M-1]=MM+1;}
                     }
 if (a[N-2][1]==MM+1){if (a[N-2][0]==1) {c++; a[N-2][0]=MM+1;}
                      if (a[N-1][1]==1) {c++; a[N-1][1]=MM+1;}
                     }
 if (a[N-2][M-2]==MM+1){if (a[N-1][M-2]==1) {c++; a[N-1][M-2]=MM+1;}
                        if (a[N-2][M-1]==1) {c++; a[N-2][M-1]=MM+1;}
                       }
 return c;
}
int blockedCats()
{int c=0;
 for (int i=1;i<N-1;i++)
  for (int j=1;j<M-1;j++)
   if (a[i][j]==MM && a[i-1][j]>=MM && a[i+1][j]>=MM &&
                      a[i][j-1]>=MM && a[i][j+1]>=MM)
   {c++;a[i][j]=MM+4;}
 return c;
}
bool escCat(int r,int c,int dist)
{if (a[r][c]==1) {a[r][c]=MM+2;return true;}
 if (a[r][c]>=dist) return false;
 int t=a[r][c];
 a[r][c]=MM+2;
 bool f=false;
 if (r) f = f || escCat(r-1,c,t);
 if (r<N-1) f = f || escCat(r+1,c,t);
 if (c) f = f || escCat(r,c-1,t);
 if (c<M-1) f = f || escCat(r,c+1,t);
 if (f) return true;
 a[r][c]=t;
 return false;
}
int escCats()
{int c=0;
 for (int i=1;i<N-1;i++)
  for (int j=1;j<M-1;j++) if (a[i][j]==MM)
  {if (escCat(i-1,j,MM)) {c++;continue;}
   if (escCat(i+1,j,MM)) {c++;continue;}
   if (escCat(i,j-1,MM)) {c++;continue;}
   if (escCat(i,j+1,MM)) c++;
  }
 return c;
}
int main()
{char b[64];
 int c=0,perCats=0,corCats,outs,saved;
 cin>>N;
 for (int i=0;i<N;i++)
 {cin>>b;
  for (int j=0;b[j];j++)
   if (b[j]=='1') {a[i][j]=MM; c++;}
   else a[i][j]=0;
 }
 M=strlen(b);
//Obvious rules
//All can escape
 if (M<3 || N<3) {cout<<c<<endl; return 0;}
//"Corner" cats
 corCats=(a[0][0]+a[0][M-1]+a[N-1][0]+a[N-1][M-1])/MM;
//"True" outputs
 outs=2*(M+N)-8;
//Waves from true outputs
 for (int i=1;i<M-1;i++) if (!a[0][i]) Wave(0,i); else perCats++;
 for (int i=1;i<M-1;i++) if (!a[N-1][i]) Wave(N-1,i); else perCats++;
 for (int i=1;i<N-1;i++) if (!a[i][0]) Wave(i,0); else perCats++;
 for (int i=1;i<N-1;i++) if (!a[i][M-1]) Wave(i,M-1); else perCats++;
//Take "free" corners - not really needed
 if (!a[0][0]) a[0][0]=MM+1;
 if (!a[N-1][0]) a[N-1][0]=MM+1;
 if (!a[0][M-1]) a[0][M-1]=MM+1;
 if (!a[N-1][M-1]) a[N-1][M-1]=MM+1;
//Save "almost there" cats
 perCats+=secLevCats();
 outs-=perCats;
//Remove "deadlocks"
 outs-=remDeadlocks();
//Saved until now
 saved=perCats+corCats;
//If no outputs left
 if (!outs) {cout<<saved<<endl; return 0;}
//Remove "blocked" cats
 c-=blockedCats();
//Out of obvious rules
// cout<<min(c,saved+outs)<<endl;
// return 0;

//greedy save
 saved+=escCats();
 cout<<saved<<endl;
 return 0;
}
/*
6
0111100
1000110
1011100
1000010
1001010
0100000
*/
