#include <iostream.h>

void delenie(int k,int x=-1)
{ for(int i=1; i<=k; i++)
    cout << "-";
  if(x>=0) cout << " " << x;
  cout << endl;
}

void linia(int k)
{ if(k>1) linia(k-1);
  delenie(k);
  if(k>1) linia(k-1);
}

void main()
{ int n,m;
  cin >> n >> m;
  delenie(m,0);
  for(int x=1; x<=n; x++)
  { linia(m-1);
    delenie(m,x);
  }
}

