#include <iostream>
using namespace std;
int main ( ) {
    int A=0, B=0, C=0, D=0, E=0, F=0, G=0;
    cin >> A >> B >> C;
    E=A+1;
    F=B;
    G=C;
    if ((B==1) || (B==3) || (B==5) || (B==7) || (B==8) || (B==10) || (B==12)) D=31;
    if ((B==4) || (B==6) || (B==9) || (B==11)) D=30;
    if (B==2) D=29;
    if (E>D)
       {
       E=1;
       F=B+1;
       }
    if ((A==31) && (B==12)) cout << "KAKVO DA IZVEDE KOGATO SE VAVEDE 31 12 2008 A?                                  POMISLETE DALI DA IZPISHE 32.12.2008 ILI 1.1.2009                               I TOGAVA KAJETE DALI ZADACHATA MI E VQRNA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! QSNO?" << endl;
    else if ((A<=D) && (B<=12) && (C==2008)) cout << "YES" << endl << E << "." << F << "." << G << endl;
    if ((A>D) || (B>12) || (C>2008) || (C<2008)) cout << "NO" << endl << D << endl;
    system("PAUSE");
    return 0;
}
