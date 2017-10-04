#include<iostream>
using namespace std;
int main () {
    int n,m,i,j,r,k,k1,k2,x,x1,x2,y,sb=0,sb1=0;
    cin >> n >> m >> r >> k ;
    x=r/m; y=r%m;
    if (y==0) { x--; y=m; }
    for (i=y-k; i<=y+k; i++) {
        if (i<1) i=0;
        else if (i>m) break;
        else sb+=x*m+i; 
        }
    sb-=r; 
    x1=x; x2=x; x1--; x2++;
    k1=k; k2=k; k1--; k2--;
    for (i=x1; i>=0; k1--, i--) {
        if (k1<0) break;
        for (j=y-k1; j<=y+k1; j++) {
            if (j<1) j=0;
            else if (j>m) break;
            else sb1+=i*m+j;
            }
            }
    for (i=x2; i<n; k2--, i++) {
        if (k2<0) break;
        for (j=y-k2; j<=y+k2; j++) {
            if (j<1) j=0;
            else if (j>m) break;
            else sb1+=i*m+j;
            }
            }
    cout << sb+sb1 ;
    cout << endl ;
    system ("PAUSE");
    return 0;
}
