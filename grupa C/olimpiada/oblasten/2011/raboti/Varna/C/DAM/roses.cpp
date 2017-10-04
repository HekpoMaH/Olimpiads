#include <iostream>
using namespace std ;
int main ()
{
    int m,n,k,i,j,h,g,a[1000][519],p=0,l=0 ;
    long long int s=0 ;
    cin >> m >> n >> k ;
    for (i=0;i<m;i++)
    for (j=0;j<n;j++) {cin >> a[i][j] ; s+=a[i][j] ;}
    for (i=0;i<m-1;i++)
    for (j=0;j<n-1;j++)
    {
        for (h=i;h<i+k;h++) for (g=j;g<j+k;g++) l+=a[h][g] ;
        if (l>p) p=l ;
        l=0 ;
    }
    cout << s-p << endl ;
    return 0 ;
}
