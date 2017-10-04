/**
PROGRAM NAME: robot-1
AUTHOR: Stoyan Kapralov
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{ int m,n,r,k;
  cin >> m >> n >> r >> k;
  
  int p = 1 + (r-1)/n;
  int q = 1 + (r-1)%n;
  
  int k2 = k % 2;
  
  int s = 0; 
  for(int i=1; i<=m; i++)
    for(int j=1; j<=n; j++)
    { int d = abs(p-i) + abs(q-j);
      if(d<=k && d%2==k2) s = s + (n*(i-1)+j);
    }
  
  cout << s << endl;
    
  return 0;
}

