#include <iostream>
using namespace std;

long long a[21][21];
int n,k;    
  
int main()
{ cin >> n >> k;

  for(int j=0; j<=k; j++)
    a[0][j] = 1;
    
  for(int i=1; i<=n; i++)
    for(int j=i; j<=n && j<=i+k; j++)
      a[i][j] = a[i-1][j] + a[i][j-1];
      
  cout << a[n][n];
  return 0;
}    
