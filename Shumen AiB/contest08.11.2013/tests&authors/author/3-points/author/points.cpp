#include <stdio.h>
#include <algorithm>
#define DEBUG
using namespace std;

#define MAXX 1024
#define MAXY 1024
#define MAXN 1000000

int bm[MAXX][MAXY];     // map na tochkite: 0 - nyama tochka; 1 - необработена
                        // отрицателно  - номер на балансьор на триъгълник
int tri[MAXX*MAXY][6], tricnt=0; //masiv na balansyorite; troykata s balansyor
                                 //i(x,y) se pomni v i-tiya red, a v bm[x][y]
                                 //se pishe -i
char glc='R';           // za nachalen izbor na cvyat
int lstx[MAXX][MAXY], //v i-tia red sa y-koordinatite na tochkite s x=i
    lsty[MAXY][MAXX]; //v j-tia red sa x-koordinatite na tochkite s y=j
//tezi sa da sledya balansiraneto  pri debug
int bx[MAXX],  //брой черни в ред i
    rx[MAXX],  //брой червени в ред i
    by[MAXY],  //брой черни в стълб j
    ry[MAXY];  //брой червени в ред i
int startx,endx,starty,endy, currx; //obhvashtsht pravoagalnik na tochkite
int x1,y1,x2,y2,x3,y3,x4,y4; // pomni 1,2,3 ili 4 tochki

// smenya alternativno cveta na parvata tochka pri ocvetyavane na
// triagalnici - vse oshte ne e yasen principat
char take_glc()
{  if(glc=='B') glc='R';else glc='B';
   return glc;
}

//tarsi tochki s ednakva x-coordinata
//v spisacite na stalb j1 i stalb j2
int search(int j1,int j2)
{  int i1=lsty[j1][0]-1,i2=lsty[j2][0]-1;
   while(i1>=1&&i2>=1)
   {  if(lsty[j1][i1]==lsty[j2][i2]) return lsty[j1][i1];
      else if(lsty[j1][i1]>lsty[j2][i2]) i1--;
           else i2--;
   }
   return -1;
}

// razpechatva troyka No=i zamenena ot balansirashta
// ako v troykta ima balansirashta - vliza rekursivno
void pr_triple(int i,char c)
{  int x,y;
   for(int j=0;j<6;j=j+2)
   {  x=tri[i][j];y=tri[i][j+1];
      if(bm[x][y]<0) {pr_triple(-bm[x][y],c);bm[x][y]=0;}
      else
      { printf("%d %d %c\n",x,y,c);
             if(c=='B') {bx[x]++;by[y]++;}
             else {rx[x]++;ry[y]++;}
      }
      if(c=='R')c='B'; else c='R';
   }
}

// razpechatva dve v red bez drugi v stalb ili
// dve v stalb bez drugi v redovete im
void pr_two(int f)
{  int c = take_glc();
   if(f==2) // tochkite sa v red
     if(by[y2]>ry[y2]) c='R';
       else if(ry[y2]>by[y2]) c='B';
         else if(by[y1]>ry[y1]) c='B';
           else if(ry[y1]>by[y1]) c='R';
   else // точките са в стълб
     if (bx[x2]>rx[x2])c='R';
       else if (rx[x2]>bx[x2]) c='B';
         else if(bx[x1]>rx[x1]) c='B';
           else if(rx[x2]>bx[x2]) c='R';
   if(bm[x2][y2]<0) //  (x2,y2) е балансираща
   { pr_triple(-bm[x2][y2],c); }
   else //  (x2,y2) е normalna
   {  printf("%d %d %c\n",x2,y2,c);
      if(c=='R'){rx[x2]++;ry[y2]++;}
      else {bx[x2]++;by[y2]++;}
   }
   lstx[x2][0]--;lsty[y2][0]--; bm[x2][y2]=0;
   if(c=='R')c='B';else c='R';
   if(bm[x1][y1]<0) //  (x1,y1) е балансираща
   { pr_triple(-bm[x1][y1],c); }
   else  //  (x1,y1) е normalna
   {  printf("%d %d %c\n",x1,y1,c);
      if(c=='R'){rx[x1]++;ry[y1]++;}
      else {bx[x1]++;by[y1]++;}
   }
   lstx[x1][0]--;lsty[y1][0]--; bm[x1][y1]=0;
}

//otpechatva chetiriagalnik
void pr_four()
{  if(bm[x1][y1]<0) //  (x1,y1) е балансираща
   {  pr_triple(-bm[x1][y1],'R'); }
   else //  (x1,y1) е normalna
   {  printf("%d %d R\n",x1,y1); rx[x1]++;ry[y1]++;}
   bm[x1][y1]=0;
   if(bm[x2][y2]<0) //  (x2,y2) е балансираща
   {  pr_triple(-bm[x2][y2],'B'); }
   else //  (x2,y2) е normalna
   {  printf("%d %d B\n",x2,y2); bx[x2]++;by[y2]++;}
   bm[x2][y2]=0;
   if(bm[x3][y3]<0) //  (x3,y3) е балансираща
   {  pr_triple(-bm[x3][y3],'R'); }
   else //  (x3,y3) е normalna
   { printf("%d %d R\n",x3,y3); rx[x3]++;ry[y3]++;}
   bm[x3][y3]=0;
   if(bm[x4][y4]<0) //  (x4,y4) е балансираща
   { pr_triple(-bm[x4][y4],'B'); }
   else //  (x4,y4) е normalna
   { printf("%d %d B\n",x4,y4); bx[x4]++;by[y4]++;}
   bm[x4][y4]=0;
}

//zapazva troyka,zamenena ot balansirashta
int pushtri()
{  tri[++tricnt][0]=x1;tri[tricnt][1]=y1;if(bm[x1][y1]>0)bm[x1][y1]=0;
   tri[tricnt][2]=x2;tri[tricnt][3]=y2;if(bm[x2][y2]>0)bm[x2][y2]=0;
   tri[tricnt][4]=x3;tri[tricnt][5]=y3;if(bm[x3][y3]>0)bm[x3][y3]=0;
   return tricnt;
}

//trie tochka ot sortiran spisak koordinati
void delp(int* a,int x)
{  int i=1;
   while(a[i]!=x)i++;
   for(;i<a[0];i++) a[i]=a[i+1];
   a[0]--;
}
// dobavya tochka v sortiran spisak koordinati
void addp(int* a,int x)
{  int i=a[0];
   if(a[0]==0) {a[0]=1; a[1]=x;}
   else { while(i>0&&a[i]>x) a[i+1]=a[i--];  a[i+1]=x;a[0]++;}
}

//maha otpechatano tochki ot spisacite
void del(int i)
{  delp(lstx[x1],y1); delp(lsty[y1],x1);
   delp(lstx[x2],y2); delp(lsty[y2],x2);
   delp(lstx[x3],y3); delp(lsty[y3],x3);
   if(i==4) {delp(lstx[x4],y4); delp(lsty[y4],x4);}
}

void cal(int i,char c)
{  if(by[tri[i][5]]>ry[tri[i][5]]) c='R';
   else if(ry[tri[i][5]]>by[tri[i][5]]) c='B';
   else if(bx[tri[i][4]]>rx[tri[i][4]]) c='R';
   else if(rx[tri[i][4]]>bx[tri[i][4]]) c='B';
   else if (by[tri[i][3]]>ry[tri[i][3]])c='R';
   else if (ry[tri[i][3]]>by[tri[i][3]]) c='B';
   else if (bx[tri[i][2]]>rx[tri[i][2]])c='R';
   else if (rx[tri[i][2]]>bx[tri[i][2]]) c='B';
   else if(by[tri[i][1]]>ry[tri[i][1]]) c='R';
   else if(ry[tri[i][1]]>by[tri[i][1]]) c='B';
   else if(bx[tri[i][0]]>rx[tri[i][0]]) c='R';
   else if(rx[tri[i][0]]>bx[tri[i][0]]) c='B';
   pr_triple(i,c);
}

int main()
{
   int N,i,j,x,y;
   scanf("%d",&N);
   for(i=0;i<N;i++)
   {  scanf("%d %d",&x,&y); bm[x][y]=1;
      lstx[x][++lstx[x][0]]=y;
      lsty[y][++lsty[y][0]]=x;
   }
   //nachalo i kray za X
   i=0;while(i<MAXX&&lstx[i][0]==0) i++;
   startx=endx=i;i++;
   while(i<MAXX) {if(lstx[i][0]!=0) endx=i; i++;}
   //spisaci na y-koordinatite po redove
   for(i=startx;i<=endx;i++)
   {  if(lstx[i][0]) sort(lstx[i]+1,lstx[i]+lstx[i][0]+1);
      bx[i]=rx[i]=0;
   }
   //nachalo i kray za Y
   i=0;while(i<MAXY&&lsty[i][0]==0) i++;
   starty=endy=i;i++;
   while(i<MAXY) {if(lsty[i][0]!=0) endy=i; i++;}
   //spisaci na x-koordinatite po stalbove
   for(i=starty;i<=endy;i++)
   {  if(lsty[i][0]) sort(lsty[i]+1,lsty[i]+lsty[i][0]+1);
      by[i]=ry[i]=0;
   }
//scaniraneto zapochva ot poslednia red
   currx=endx;
   while(currx>=startx)
   {  //propuskame praznite redove
      if(lstx[currx][0]==0) { currx--;continue;}
      if(lstx[currx][0]==1) //(x1,y1) edinstvena v reda
      {   x1=currx, y1=lstx[currx][1];
          if(lsty[y1][0]==1) // (x1,y1) единствена и в стълба
          { int c=take_glc();
            if(by[y1]>ry[y1]) c='R';
               else if(ry[y1]>by[y1]) c='B';
            if(bm[x1][y1]<0) //  ako (x1,y1) е балансираща
            {  cal(-bm[x1][y1],c); }
            else //  (x1,y1) е normalna
            {  printf("%d %d %c\n",x1,y1,c);
               if(c=='R'){rx[x1]++;ry[y1]++;}
               else {bx[x1]++;by[y1]++;}
            }
            lstx[x1][0]--;lsty[y1][0]--; bm[x1][y1]=0;
            currx--;continue;
          }
          else //ne e edinstvena v stulba
          {  y2=y1;x2=lsty[y2][lsty[y2][0]-1];//vtora tochka v stalba
             if(lstx[x2][0]==1) //vtorata tochka e sama v reda
             {  pr_two(1); currx--;continue; }
             else //vtorata tochka ne e sama v reda
             {  x3=x2;
                if(lstx[x2][lstx[x2][0]]==y2)//ako (x2,y2) e posledna v reda x2
                {  y3=lstx[x2][lstx[x2][0]-1];  } //(x3=x2,y3) e вляво
                else //ako (x2,y2) ne e posledna v reda x2
                {  y3=lstx[x2][lstx[x2][0]];    } //(x3,y3) e poslednata vdyasno
                if(bm[x1][y3]!=0)
                {  int z=pushtri(); del(3); cal(z,take_glc());
                   if(bm[x1][y3]<0) cal(-bm[x1][y3],take_glc());
                }
                else
                {  bm[x1][y3]=-pushtri();del(3);
                   addp(lsty[y3],x1);addp(lstx[x1],y3);
                }
             }
          }
      }
      else // ima pone 2 tochki v reda
      {   x1=x2=currx; y1=lstx[x1][lstx[x1][0]-1]; y2=lstx[x2][lstx[x2][0]];
          if(lsty[y1][0]==1&&lsty[y2][0]==1)//dvete tochki sa sami v stulb
          { pr_two(2); continue; }
          x3=search(y1,y2);
          if(x3>=0&&x3!=x1) //chetiriagalnik
          {  x4=x3;y3=y2;y4=y1; del(4);pr_four(); continue; }
          int y;
          if(lsty[y2][0]>1)// v stulba na dyasnata ima tochka
          {  y=y1;y3=y2; x3=lsty[y2][lsty[y2][0]-1]; }//prednata v stulba na (x2,y2)
          else // v staulba na lyavata ima tochka
          {  y=y2;y3=y1; x3=lsty[y1][lsty[y1][0]-1];
             int tmp=x1;x1=x2;x2=tmp;tmp=y1;y1=y2;y2=tmp;
          }//prednata v stulba na (x1,y1)
          if(bm[x3][y]!=0)
          {  int z=pushtri();del(3);cal(z,take_glc());
             if(bm[x3][y]<0) cal(-bm[x3][y],take_glc());
           }
          else
          {  bm[x3][y]=-pushtri();del(3);
             addp(lstx[x3],y);addp(lsty[y],x3);
          }
      }
   }
   return 0;
}
