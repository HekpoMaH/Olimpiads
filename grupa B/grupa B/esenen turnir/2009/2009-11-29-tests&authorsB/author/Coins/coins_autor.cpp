#include <iostream>
using namespace std;

int t[3][8];
string f[13][2];

int main()
{ string res = "xxx";
  for(int w=0; w<3; w++)
  { for(int j=0; j<4; j++)
      cin >> t[w][j];
    cin >> res[w];
    for(int j=4; j<8; j++)
      cin >> t[w][j];
  }
  
  for(int c=1; c<=12; c++)
  { f[c][0]=f[c][1]="===";
    for(int w=0; w<3; w++)
    { for(int j=0; j<4; j++)
      { int c = t[w][j];
        f[c][0][w] = '<'; 
        f[c][1][w] = '>'; 
      }
      for(int j=4; j<8; j++)
      { int c = t[w][j];
        f[c][0][w] = '>'; 
        f[c][1][w] = '<'; 
      }
    }
  }
         
  int sol=0;
  int fls;
  char sgn;
  for(int c=1; c<=12; c++)
  { if(f[c][0]==res) { sol++; fls=c; sgn='-'; }
    if(f[c][1]==res) { sol++; fls=c; sgn='+'; }
  }  
           
  if(sol==1) cout << fls << sgn << endl;
  if(sol==0) cout << "impossible" << endl;     
  if(sol>=2) cout << "indefinite" << endl;     
 
  return 0;
}
    
