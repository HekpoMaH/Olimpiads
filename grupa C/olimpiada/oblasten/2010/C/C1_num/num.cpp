#include <iostream>
using namespace std;

bool ok(int x)
{ int a[10]={0};
  
  while(x>0)
  { int d = x % 10;
    if(a[d]==1) return false;
    a[d]=1;
    x = x / 10;
  }
  
  return true;
}       

int main()
{ int a,b;

  cin >> a >> b;
  
  int cnt=0;
  
  for(int x=a; x<=b; x++)
    if(ok(x)) cnt++;
    
  cout << cnt << endl;
  
  return 0;
}
    
