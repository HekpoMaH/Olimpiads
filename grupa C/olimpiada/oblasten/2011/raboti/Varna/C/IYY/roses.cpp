#include<iostream>
using namespace std;
long long int a[1000],sb1[1000][1000],sb2[1000];
int main () {
    long long int n,m,k,i,j,h,sb=0,maxsb2=-1;
    cin >> n >> m >> k ;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            cin >> a[j] ;
            sb+=a[j];
            if (j>0) { sb1[i][j]=sb1[i][j-1]+a[j];
                       sb2[j]+=sb1[i][j-1]+a[j]; }
            else { sb1[i][j]=a[j];
                   sb2[j]+=a[j]; }
            if (j>k-1) { sb1[i][j]-=a[j-k]; sb2[j]-=a[j-k]; }
            if (i>k-1) { sb2[j]-=sb1[i-k][j];
                         if (maxsb2<sb2[j]) maxsb2=sb2[j]; }
            }
            }
    cout << sb-maxsb2 ;
    cout << endl ;
    system ("PAUSE");
    return 0;
}
