#include <iostream>
using namespace std;
void gen(long long k)
{for (long long i=1;i<=10;i++)
 {if (k&1) cout<<2*i*(k+1)+1;
  else cout<<i*(k+2)+1;
  if (i<10) cout<<' ';
 } 
 cout<<endl;
}
int main(void)
{
 long long k;
 cin>>k;
 gen(k);
 return 0;
}
