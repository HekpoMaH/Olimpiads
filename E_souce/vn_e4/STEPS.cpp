#include <iostream>
using namespace std;
int main ( ) {
    int N, H, L, A, B, C, D, E, F, G, I, J, K, M, O, P;
    char S;
    cin >> N >> H >> L;
    cin >> S;
    for (A=1;A<=L+1;A++)
        {
        cout << S;
        }
    cout << endl;
    for (B=1;B<=H*N-N-1;B++)
        {
        if ((B==1) || (B==2))
           {
           cout << S;
           for (C=1;C<=L-1;C++)
               {
               cout << " ";
               }
           cout << S;
           for (C=1;C<=L-1;C++)
               {
               cout << " ";
               }
           for (C=1;C<=L;C++)
               {
               cout << S;
               }
           cout << endl;
           }
        if ((B==3) || (B==4))
           {
           cout << S;
           for (I=1;I<=L+L-1;I++)
               {
               cout << " ";
               }
           cout << S;
           for (I=1;I<=L+L-1;I++)
               {
               cout << " ";
               }
           for (I=1;I<=L;I++)
               {
               cout << S;
               }
           cout << endl;
           }
        if ((B==5) || (B==6))
           {
           cout << S;
           for (J=1;J<=L+L+L-1;J++)
               {
               cout << " ";
               }
           cout << S;
           for (J=1;J<=L+L-1;J++)
               {
               cout << " ";
               }
           for (J=1;J<=L;J++)
               {
               cout << S;
               }
           cout << endl;
           }
        if ((B==7) || (B==8))
           {
           cout << S;
           for (K=1;K<=L+L+L+L-1;K++)
               {
               cout << " ";
               }
           cout << S;
           for (K=1;K<=L+L-1;K++)
               {
               cout << " ";
               }
           for (K=1;K<=L;K++)
               {
               cout << S;
               }
           cout << endl;
           }
        if ((B==9) || (B==10))
           {
           cout << S;
           for (M=1;M<=L+L+L+L+L-1;M++)
               {
               cout << " ";
               }
           for (M=1;M<=L+L-1;M++)
               {
               cout << " ";
               }
           cout << S;
           for (M=1;M<=L;M++)
               {
               cout << S;
               }
           cout << endl;
           }
        if ((B==11) || (B==12))
           {
           cout << S;
           for (O=1;O<=L+L+L+L+L+L-1;O++)
               {
               cout << " ";
               }
           cout << S;
           for (O=1;O<=L+L-1;O++)
               {
               cout << " ";
               }
           for (O=1;O<=L;O++)
               {
               cout << S;
               }
           cout << endl;
           }
        if ((B==13) || (B==14))
           {
           cout << S;
           for (P=1;P<=L+L+L+L+L+L+L-1;P++)
               {
               cout << " ";
               }
           cout << S;
           for (P=1;P<=L+L-1;P++)
               {
               cout << " ";
               }
           for (P=1;P<=L;P++)
               {
               cout << S;
               }
           cout << endl;
           }
        }
    for (D=1;D<L*N+1;D++)
        {
        cout << S;
        }
    cout << endl;
    system ("PAUSE");
    return 0;
}
