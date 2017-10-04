#include <iostream>
#include <algorithm>
using namespace std;

int comb(int n, int k)
{ if(k<0 || k>n) return 0;
  if(k > n-k) k = n-k;
  if(k==0) return 1;
  long c=n;
  for(int i=2; i<=k; i++)
    c = c * (n-i+1)/i;
  return c;   
}


int num(int a[])
{ int r = 0;
  for(int i=1; i<=6; i++)
    for(int k=a[i-1]+1; k<a[i]; k++)
      r = r + comb(49-k,6-i);
  return r;
}      

int a[7],b[7];

int main()
{
  for(int i=1; i<=6; i++)
    cin >> a[i];
  for(int i=1; i<=6; i++)
    cin >> b[i];
    
  int numa = num(a);
  int numb = num(b);
  
  int ans=0;
  if(numa<numb) ans = numb-numa-1; 
  
  cout << ans << endl;
  
  return 0;
}      
