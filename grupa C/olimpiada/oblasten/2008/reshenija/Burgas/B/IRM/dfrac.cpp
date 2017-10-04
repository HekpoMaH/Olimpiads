#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
  long long int a, b, k;
  int p;
  cin >> a >> b >> k >> p;    
  double x, y, z;
  x=1.0*a/b;
  long long i=-1;
  if (k==1)
  {
    while (i<p-1)
    {       
      int c=x*10;
      cout << c;
      i++;
      x*=10;
      x=x-floor(x); 
    }
    
  }
  if (k!=1)
  {while (i<k-2)
  {
    i++;
    x*=10;
  }
  
  x=x-floor(x);
  i=0;
  while (i<p)
  {       
    int c=x*10;
    cout << c;
    i++;
    x*=10;
    x=x-floor(x); 
  }
  
  }
  cout << endl;
 // system ("pause");
  return 0;
}

