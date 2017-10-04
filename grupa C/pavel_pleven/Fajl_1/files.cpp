#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string   Ns[20001],Ks[20001];
int    bNs,bKs,Sum;
int    M1[20001],M2[20001],M3[20001],M4[20001];

int WyrniNomNs(string s) {
int i,k;
    k=0;
    for( i=1;i<=bNs;i++)
     if (Ns[i]==s) {
       k=i;
       break;
    }
    return k;
}

int ObrBrM1(int i1,int i2) {

string s1,s2;
int br,i,d;

    s1=Ns[i1];
    s2=Ns[i2];
    d=s1.size();
    br=0;
    for (i=0;i<d;i++)
     if (s1[i]==s2[i])
      br++;
      else
      break;
    br++;
    return br;
}

void ObrM1() {
int i;

    M1[1]=1;
    for (i=2;i<=bNs;i++){
      if (Ns[i][0]!=Ns[i-1][0]){
        M1[i]=1;
       }
       else {
        M1[i]=min(M1[i-1]+1,ObrBrM1(i-1,i));
       }
     }
// Включва стрелка нагоре
    M2[bNs]=M1[bNs];
    for (i=bNs;i>=2;i--)
      if (M1[i-1]-M2[i]>1) 
       M2[i-1]=M2[i]+1;
       else
       M2[i-1]=M1[i-1];
// Включва стрелка нагоре
// когато е активен файл по средата
// и се проверява с 2 натискания да се отиде до
// последния файл - 1 натискане за първия и стрелка нагоре
// да се иде до последния
    if (M2[bNs]>2){
      M3[bNs]=2;
      for (i=bNs;i>=2;i--)
        if (M2[i-1]-M3[i]>1)
         M3[i-1]=M3[i]+1;
         else
         M3[i-1]=M2[i-1];
     }
     else
     for (i=1;i<=bNs;i++) M3[i]=M2[i];
// Включва стрелка нагоре
// когато e активен ПЪРВИЯ файл
// тогава до последния може да се стигне с 1 натискане
// на стрелка нагоре
    M4[1]=0;
    for (i=2;i<=bNs;i++)
      if (M2[i]-M4[i-1]>1)
      M4[i]=M4[i-1]+1;
      else
      M4[i]=M2[i];
    if (M2[bNs]>1)
     {
      M4[bNs]=1;
      for (i=bNs;i>=2;i--)
        if (M2[i-1]-M4[i]>1) M4[i-1]=M4[i]+1;
     }
}


void Resh() {
int  i,Nom,NomS;
string s;

    Nom=WyrniNomNs(Ks[1]);
    if (Nom==1)
     Sum=0;
     else
     Sum=M4[Nom];
     NomS=Nom;
     for (i=2;i<=bKs;i++) {
       Nom=WyrniNomNs(Ks[i]);
       if (NomS==1)
        Sum=Sum+min(M4[Nom],abs(NomS-Nom));
        else
        Sum=Sum+min(M3[Nom],abs(NomS-Nom));
       NomS=Nom;
      }
}

void Pechat (){
int i;
    for (i=1; i<=bNs;i++)
     cout<<setw(15)<<Ns[i]<<setw(5)<<M1[i]<<" "<<M2[i]<<" "<<M3[i]<<" "<<M4[i]<<endl;
}

int main () {
int i;
  cin>>bNs;
  for (i=1;i<=bNs;i++) cin>>Ns[i];
  cin>>bKs;
  for (i=1;i<=bKs;i++) cin>>Ks[i];
  ObrM1();
  Pechat ();
  Resh();  
  cout<<Sum<<endl;
system ("pause");
return 0;
}
