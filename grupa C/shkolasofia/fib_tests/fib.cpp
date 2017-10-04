#include <iostream>

using namespace std;

#define LL long long
const int DIM=2;
//const int MOD = 10;
LL m;

struct matr
{  LL el[DIM][DIM];
   void prn()
     { for(int i=0; i<DIM; i++)
         { for(int j=0; j<DIM; j++)
             cout << el[i][j] << "; ";
           cout << endl;
         }
        cout << endl;
     }
};

matr operator*(matr a, matr b)
{ matr c;
  for(int i=0; i<DIM; i++)
    for(int j=0; j<DIM; j++)
      { c.el[i][j] = 0;
        for(int k = 0; k< DIM; k++)
          c.el[i][j] = (c.el[i][j] +  a.el[i][k]*b.el[k][j])% m;
      }
  return c;
}

matr operator^(matr a, LL p)
{   matr ans = {1,0,
                0,1};
    while(p)
    { if (p&1) ans = ans*a;
      a = a*a;
      p >>= 1;
    }
    return ans;
}

int main()
{ matr a1 = {1, 1,
             1, 0};
  LL n;
  cin >> n >> m;
  if (n == 1 || n == 2)
    { cout << 1 % m << endl;
      return 0;
    }
  matr x = a1^(n-2);
  cout << (x.el[0][0] + x.el[0][1]) % m << endl;

  return 0;
}
