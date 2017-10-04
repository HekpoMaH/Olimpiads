#include <iostream>

using namespace std;
int N,M;
int a1,a2,a3;
int bW,bD,bP;
int v;


void Prowerka(){
bool Fl;

    Fl=false;
    if (v==0)
     if (a3!=0) Fl=true;
    if (v==1)
     if (a3!=1) {
        Fl=true;
        if (a3==2) bW++;
        else
        if (a2==2) bP++;
    }
    if (v==2)
     if (a3!=2) {
        Fl=true;
        if (a3==1) bD++;
        else
        if (a2==1) bD++;
     }
    if (Fl) {
      a1=a2;
      a2=a3;
      a3=v;
    }
}
int main () {

int i,h1,h2,k;

     cin >> k;
     for(int j=1; j<=k; j++)
     {
       a1=0;a2=0;a3=0;
       bW=0;bD=0;bP=0;
       cin>>N;
       cin>>h2;
       for (i=2;i<=N;i++){
         cin>>h1;
         if (h1==h2)
          v=0;
          else
           if (h1<h2)
            v=1;
            else
            v=2;
         Prowerka();
         h2=h1;
       }
    cout<<bW<<" "<<bD<<" "<<bP<<endl;
    }
  return 0;
}
