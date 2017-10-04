#include <iostream>
using namespace std;
unsigned char L[10000]={0};
int a,b,mx=0;
long step(long a)
{if (a&1) return 3*a+1;
 return a>>1;
}
long depth(long a)
{long c=1;
 while (a!=1)
 {a=step(a);
  c++;
 }
 return c;
}
void tab(long st, long en)
{int m;
 for (long i=st;i<=en;i++)
 {m=depth(i);
  L[m]++;
  if (m>mx) mx=m;
 }
}
int main (void)
{int m;
 cin>>a>>b;
 tab(a,b);
 m=0;
 for (int i=1;i<=mx;i++) if (L[i]>m) m=L[i];
 cout<<m<<endl;
 return 0;
}
