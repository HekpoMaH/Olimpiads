/**
PROGRAM NAME: robot-2
AUTHOR: Stoyan Kapralov
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int m,n,r,k;
  
int num(int i, int j)
{ if(1<=i && i<=m && 1<=j && j<=n) return n*(i-1)+j;
  return 0;
}
  
int main()
{ cin >> m >> n >> r >> k;
  
  int p = 1 + (r-1)/n;
  int q = 1 + (r-1)%n;
  
  int s = 0;
  if(k%2==0) s = r; 
  for(int d=k; d>0; d=d-2)
  { s = s + num(p-d,q)+num(p+d,q)+num(p,q-d)+num(p,q+d);
    for(int dp = 1; dp<d; dp++)
    { int dq = d - dp;
      s = s + num(p+dp,q+dq)+num(p+dp,q-dq)+num(p-dp,q+dq)+num(p-dp,q-dq);
    }
  }
     
  cout << s << endl;
    
  return 0;
}

