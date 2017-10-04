#include <iostream>
using namespace std;
int main()
 {
  int n, t[20][20], i, j, k, m, f, d, s=0;
  bool sym=true;
  cin>>n;
  for(i=0; i<n; i++) for(j=0; j<n; j++) cin>>t[i][j];
  j=n-1;
  m=n-2;
  f=n-1;
  d=n-1;
  for(i=0; i<=n-2; i++)
   {
    for(k=0; k<=m; k++) { if(t[i][k]!=t[j][d]) sym=false;  j--; }
    d--;
    m--;
    j=n-1;
   }
  if(sym)
   {
    for(i=0; i<n; i++) for(j=0; j<n; j++) if(t[i][j]%3==0 && t[i][j]!=0) cout<<t[i][j]<<' ';
   }
  else
   {
    for(i=0; i<n; i+=2) for(j=0; j<n; j++) s+=t[i][j];
    cout<<s;
   }
  return 0;
 }
      
