#include<iostream>
using namespace std;

int main()
{ 
    int p, q, p1, q1, br;
    cin >> p >> q;
    if (p%2 == 1 && q%2 == 1)
      { cout << 0 << endl;
        return 0;
      } 
    p1=p; q1=q; br=0;
    do
      { if (p1%2 == 0)
          { p1 = p1/2;
            q1 = p1 + q1;
          }
        else
          { q1 = q1/2;
            p1 = p1 + q1;
          }
        br++;
      }while(p1 != p && br < p+q);
    
    if (br == p+q) cout << 0 << endl;
    else cout << br << endl;    
    
    return 0;
}  
