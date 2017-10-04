#include <iostream>
using namespace std;
const int MAXB = 30000010;
int d[MAXB];

int main()

{ long a, a1, b;
  long long k;
  int p;
  cin >> a >> b >> k >> p;
  a1 = a;
  long m, t;
  bool pr = true;
  long n = 0;
  while(pr)
  { n++;
    a = (10*a)%b;
    if (d[a] == 0)
      d[a] = n;    
    else 
      { m = d[a];
        t = n - m;   
        pr = false;
      }    
  }     
  long x;
  if (k < m+1) x = k;
  else x = m+1+(k-m-1)%t;
  for(long i=1; i<x; i++)
    a1 = (10*a1)%b;
  for(int j=0; j<p; j++)
    { cout << (10*a1)/b;
      a1 = (10*a1)%b;
    }
  cout << endl;   
  return 0;
}
