#include <iostream>
using namespace std;

int main()
{ int k=0;
  for(int x=10000; x<=99999; x++)
  { int a = x/10000;
    int b = x/1000%10;
    int c = x/100%10;
    int d = x/10%10;
    int e = x%10;
    
    if(b==a+c && d==c+e) 
    { k++; 
      cout << x << " " << k << endl;
    }
  }
  return 0;  
}