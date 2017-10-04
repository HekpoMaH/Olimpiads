
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

struct Monster {
     int l,r,xy;
    };


    int bHor,bVer,dX,dY;
    Monster Hor[15001],Ver[15001];
    int N,BrH,BrV;
    long long brHor,brVer,brHV;
    bool flL,flR;
    

bool fHor( Monster m1, Monster m2) {
    if (m1.xy<m2.xy) return true;
     else
     if (m1.xy==m2.xy) {
      if ((m1.l==1)&&(m2.l==1)) {
        if (m1.r>m2.r)     
            return true;
            else
            return false;
      }
      else
      if ((m1.r==dX)&&(m2.r==dX)) {
        if (m1.l<m2.l)     
            return true;
            else
            return false;
      }
      else
      if ((m1.l==1)&&(m2.r==dX)) return true;
      else
      return false;
    }
    else
    return false;
}

bool fVer( Monster m1, Monster m2) {
    if (m1.xy<m2.xy) return true;
     else
     if (m1.xy==m2.xy) {
      if ((m1.l==1)&&(m2.l==1)) {
        return (m1.r>m2.r);
      }
      else
      if ((m1.r==dY)&&(m2.r==dY)) {
        return (m1.l<m2.l);
      }
      else
      return ((m1.l==1)&&(m2.r==dY));
    }
    else
    return false;
}

// Образува новите хоризонтални
void ObrNowiHor() {
int i;
    flL=false; flR=false;
    BrH=1;
    if (Hor[1].l==1) flL=true;
    else
    flR=true;
    for (i=2;i<=bHor;i++) {
     if (Hor[i].xy!=Hor[i-1].xy) {
      if ((flL)&&(flR)) {
       if (Hor[BrH-1].r>=Hor[BrH].l) {
        Hor[BrH-1].r=dX;
        BrH--;
       }
       else
       if ((Hor[BrH].l-Hor[BrH-1].r)==1) {
        Hor[BrH-1].r=dX;
        BrH--;
       }
      }      
      flL=false; flR=false;
     }
     if (Hor[i].l==1) {
      if (!flL) {
        flL=true;
        BrH++;
        Hor[BrH]=Hor[i];
      }
     }
     if (Hor[i].r==dX) {
      if (!flR) {
        flR=true;
        BrH++;
        Hor[BrH]=Hor[i];
      }
     }
    }
   if (Hor[BrH].xy==Hor[BrH-1].xy) {
    if ((flL)&&(flR)) {
     if (Hor[BrH-1].r>=Hor[BrH].l) {
      Hor[BrH-1].r=dX;
      BrH--;
     }
     else
     if ((Hor[BrH].l-Hor[BrH-1].r)==1) {
      Hor[BrH-1].r=dX;
      BrH--;
     }
    }      
   }
}

void ObrNowiVer() {
int i;
    flL=false; flR=false;
    BrV=1;
    if (Ver[1].l==1) flL=true;
    else
    flR=true;
    for (i=2;i<=bVer;i++) {
     if (Ver[i].xy!=Ver[i-1].xy) {
      if ((flL)&&(flR)) {
       if (Ver[BrV-1].r>=Ver[BrV].l) {
        Ver[BrV-1].r=dY;
        BrV--;
       }
       else
       if ((Ver[BrV].l-Ver[BrV-1].r)==1) {
        Ver[BrV-1].r=dY;
        BrV--;
       }
      }
      flL=false; flR=false;
     }
     if (Ver[i].l==1) {
      if (!flL) {
        flL=true;
        BrV++;
        Ver[BrV]=Ver[i];
      }
     }
     if (Ver[i].r==dY) {
      if (!flR) {
        flR=true;
        BrV++;
        Ver[BrV]=Ver[i];
      }
     }
    }
   if (Ver[BrV].xy==Ver[BrV-1].xy) {
    if ((flL)&&(flR)) {
     if (Ver[BrV-1].r>=Ver[BrV].l) {
      Ver[BrV-1].r=dY;
      BrV--;
     }
     else
     if ((Ver[BrV].l-Ver[BrV-1].r)==1) {
      Ver[BrV-1].r=dY;
      BrV--;
     }
    }
   }
}

int main () {
    
    int i,j,y,x;
    char c;
    
    bHor=0;
    bVer=0;
     cin>>N>>dY>>dX;
     for (i=1;i<=N;i++) {
       scanf ("%d %d %c",&y,&x,&c);
       if (c=='l'||c=='r') {
         bHor++;
         Hor[bHor].l=(c=='l')+(c=='r')*x;
         Hor[bHor].r=(c=='l')*x+(c=='r')*dX;
         Hor[bHor].xy=y;
       }
       else 
       {
         bVer++;
         Ver[bVer].l=(c=='u')+(c=='d')*y;
         Ver[bVer].r=(c=='u')*y+(c=='d')*dY;
         Ver[bVer].xy=x;
       }
      }
    
    sort(Hor,Hor+bHor+1,fHor);
    sort(Ver,Ver+bVer+1,fVer);
// Образува новите хоризонтални
    if (bHor>0)ObrNowiHor();
// Образува новите хоризонтални
    if (bVer>0)ObrNowiVer();
    brHor=0; brVer=0; brHV=0;
    for (i=1;i<=BrH;i++) brHor+=Hor[i].r-Hor[i].l+1;
    for (i=1;i<=BrV;i++) brVer+=Ver[i].r-Ver[i].l+1;

    for (i=1;i<=BrH;i++)
     for (j=1;j<=BrV;j++)
      if (Hor[i].l<=Ver[j].xy) 
       if (Ver[j].xy<=Hor[i].r)
        if (Ver[j].l<=Hor[i].xy) 
         if (Hor[i].xy<=Ver[j].r)
          brHV++;
    
    cout<<brHor+brVer-brHV<<endl;
    
    
//    system ("pause");
	return 0;
}

/*

5 5 5
1 2 l
1 4 l
3 2 l
3 3 r
4 4 u

*/
