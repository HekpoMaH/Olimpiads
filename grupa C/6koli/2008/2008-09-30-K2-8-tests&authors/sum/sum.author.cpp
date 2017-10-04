#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
  unsigned long long int v=0, n=0;
  while(1)
  { char c; scanf("%c",&c);
    if(c<'1') break;
    n++;
    v = v + (long long int)((int)c-(int)'0');
  }
  n=(n*(n-1))/2-(n-1);
  cout << v*n << endl;
}
