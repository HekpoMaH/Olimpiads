#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a,b;

int main()
{ int x; 
  for(int i=1; i<=6; i++)
  { cin >> x;
    a.push_back(x);
  }
  for(int i=1; i<=6; i++)
  { cin >> x;
    b.push_back(x);
  }

  int ans=0;
  while(a<b) 
  { ans++;
    int i=5;
    while(a[i]==44+i) i--;
    a[i]++;
    for(int j=i+1; j<6; j++)
      a[j] = a[j-1]+1;
  }
  if(ans>0) ans--;    
    
  cout << ans << endl;
  
  return 0;
}      
