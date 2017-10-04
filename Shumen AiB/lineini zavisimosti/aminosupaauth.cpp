/*
TASK:aminosoup
LANG:C++
*/
#include <iostream>
#include<cstring>
using namespace std;
struct matr
{
   unsigned long long a[64][64];
    matr()
    {
        memset(a, 0, sizeof(a));
    }
};
matr cool;

unsigned long long n, m;
long long temp = 0;
long long MOD = 602214179;
matr helper1;    // помощни матрици
matr helper2;

void rec(int mask, int pos)   // генерира всички профили съвместими с даден.
{
  if (pos < 0){ cool.a[mask][temp] = 1;return; }
 if(mask&(1<<pos)) {temp = temp*2; rec(mask, pos-1); temp/=2;}

    else
    {
        if(pos >=1 && !(mask&(1<<pos)) && !(mask&(1<<(pos-1))))
            {
                temp = temp *4;
                rec(mask, pos-2);
                temp/=4;
            }
        if(!(mask&(1<<pos)))
            {
                temp = temp*2 + 1;
                rec(mask, pos-1);
                temp/=2;
            }
    }
}

matr umn (matr &p1, matr &p2) // умножение на матрици
{
    int i, j, k;
    int cap = 1<<m;
    for(i = 0; i<cap; i++)
        for(j = 0; j<cap; j++)
         {
         helper1.a[i][j] = 0;
            for (k = 0; k<cap; k++)
                {
                    helper1.a[i][j] += p1.a[i][k]*p2.a[k][j];
                    helper1.a[i][j]%=MOD;
                }
        }

                return helper1;
}
matr stepen(matr &p, unsigned long long pos)   // Бързо повдигане в степен
{

    if(pos == 1) { return p;}

    if(pos%2) {helper2 = stepen(p, pos-1); return umn(p, helper2);}

    helper2 = stepen(p, pos/2);

    return  umn(helper2, helper2);
}
int main()
{
    cin>>n>>m;

    if(n<m) swap(n, m);

    int i = 0;
    for(i = 0;i<(1<<m);i++)
       {
            temp = 0;
             rec(i, m-1);

        }
 matr start;
 start.a[0][0] = 1;

    matr ret;
      ret = stepen(cool, n);
      ret = umn( ret, start);

    cout<<ret.a[0][0]%MOD<<"\n";
    return 0;
}
