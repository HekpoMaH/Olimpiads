#include <iostream>
using namespace std;

int getRand(int a, int b)
{ int x;
  x = rand();
  x = (x<<16) + rand();
  x = a + x % (b-a+1);
  return x;
}  

int main()
{ int n,a,b,seed;
  cin >> n >> a >> b >> seed;
  
  int m=1;
  for(int i=1; i<=n; i++)
    m = 4*m;
    
  cout << n << endl;
  
  srand(seed);
  for(int i=1; i<m; i++)
    cout << getRand(a,b) << " ";
  cout << getRand(a,b) << endl;
  
  return 0;
}      
