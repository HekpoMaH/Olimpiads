#include <iostream>
using namespace std;

bool ok(int x)
{  int a = x/10000;
   int b = x/1000%10;
   int c = x/100%10;
   int d = x/10%10;
   int e = x%10;
   if(b==a+c && d==c+e) return true;
   return false; 
}

int main()
{ int y;
  cin >> y;
  int k=0;
  if(ok(y)) 
    for(int x=10000; x<=y; x++)
      if(ok(x)) k++;
  cout << k << endl;
  return 0;  
}