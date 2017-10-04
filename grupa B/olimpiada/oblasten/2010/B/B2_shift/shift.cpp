#include <iostream>
using namespace std;


int a[20][20];

int main ()
{  int p,q,n;
   cin >> p >> q >> n;

   a[n-1][n] = 1;
   for(int i=n-2; i>=p; i--)
     for(int j=n; j>i; j--)
       a[i][j] = a[i+1][j] + a[i][j+1];  
   cout << a[p][q] << endl;       
   return 0;
}
