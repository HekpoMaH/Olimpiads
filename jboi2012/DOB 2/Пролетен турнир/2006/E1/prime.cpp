#include <iostream>
using namespace std;

int c;

void factor(int n)
{ int d=2;
  while(n>1)
   if(n%d==0) {n=n/d; c++;}
   else d++;
}       

int main()
{
   int a,b;
   cin >> a >> b;
   for (int i=a;i<=b;i++) factor(i);
   cout << c << endl;
   return 0;
}


