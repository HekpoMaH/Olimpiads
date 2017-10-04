#include <iostream>
using namespace std;
int main ( ) {
    int A, B, C, D, E, F;
    cin >> A;
    B=1;
    C=1;
    for (D=1;D<=A-2;D++)
        {
        if (D%2==0) C=B+C;
        if (D%2==1) B=B+C;
        }
    if (A%2==0) cout << C << endl;
    if (A%2==1) cout << B << endl;
    system("PAUSE");
    return 0;
}
