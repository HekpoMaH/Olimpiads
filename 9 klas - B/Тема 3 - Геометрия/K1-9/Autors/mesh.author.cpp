#include<iostream>
using namespace std;

long long int a,b,d;

long long int nod(long int a, long int b)
{
  while(a != b)
  if(a>b) a=a-b; else b=b-a;
  return a;
}

int main()
{
cin >> a >> b;
d=nod(a,b);
cout << a+b-d+2*(d-1) << endl;
}
