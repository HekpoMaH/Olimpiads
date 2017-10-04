// gcc 2.95.3

#include<iostream>
using namespace std;
long long int a,b;

long long int euclid(long long int a, long long int b)
{
 while(a != b)
 if(a>b)a=a-b; else b=b-a;
 return a;
}

void find(long long int a, long long int b)
{
  long long int c,x1,x2,z;

  while(a != 1)
  {
   z = b/a + 1;//a/b=1/y1+1/y2(*b*y1*y2) -> a*y1*y2=b*y2+b*y1 -> b*(y1+y2)=a*y1*y2;
   cout << z << " ";
   x1 = z*b;
   x2 = a*z - b;
   c = euclid(x1,x2);
   a = x2/c;
   b = x1/c;
  }
  cout << b << " ";
}

int main()
{
 cin >> a >> b;
 long long int c = euclid(a,b);
 a = a/c;
 b = b/c;
 find(a,b);
 cout << endl;
 return 0;
}
