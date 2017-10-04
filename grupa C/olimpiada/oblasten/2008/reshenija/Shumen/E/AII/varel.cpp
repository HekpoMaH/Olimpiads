#include<iostream>
using namespace std;
int main()
{int V,K,br=0,N;
char s;
cin>>V>>K>>N;

do {cin>>s;br++;
if (s=='+') V=V+K;
if (s=='-') V=V-K;}
 while (br<N);

cout<<V;

return 0;
}
