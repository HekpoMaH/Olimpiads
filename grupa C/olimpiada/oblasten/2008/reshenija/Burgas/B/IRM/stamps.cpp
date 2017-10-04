#include <iostream>
using namespace std;
int main ()
{
  int s, n, m[3000], broi[3000];
  cin >> s >> n;
  int br=0, sbr;
  for (int i=0; i<n; i++) cin >> m[i];
  sort (m, m+n);
  int sc=s;
  int min=9999;
  int k=n-1;
  do
  {
    sbr=0;
    int p=k;
    do
    {
      br=sc/m[p];
      sbr+=br;
      sc=sc-(br*m[p]);
      p--;
    }
    while (sc>0);
    if (sc==0 && sbr<min) min = sbr;
    k--;
    sc=s;
  }
  while (k>0);
  cout << min << endl;
 // system ("pause");
  return 0; 
}


