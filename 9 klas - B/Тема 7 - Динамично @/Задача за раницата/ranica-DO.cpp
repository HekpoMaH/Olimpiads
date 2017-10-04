#include <iostream>
using namespace std;
int N, M, m[1000], c[1000];
int Fn[1000];
bool set[1000][1000];

void calculate()
{ int maxValue, maxIndex, i, j;
    for (i=1; i<=M; i++)
    {   maxValue = maxIndex = 0;
        for (j=1; j<=N; j++)
          if (m[j]<=i && !set[i-m[j]][j])
            if (c[j] + Fn[i-m[j]] > maxValue)
            {  maxValue = c[j] + Fn[i-m[j]];
               maxIndex = j;
            }
        if (maxIndex > 0)
        {  Fn[i] = maxValue;
           for(int k=0;k<=N-1;k++) set[i][k]=set[i-m[maxIndex]][k];
           set[i][maxIndex] = 1;
        }
        if (Fn[i] < Fn[i-1])
        {  Fn[i] = Fn[i-1];
           for(int k=0;k<=N-1;k++) set[i][k], set[i-1][k];
        }
     }
  cout << "Max value: " << Fn[M]<<endl;
  cout<<"Taken things: ";
  for (int i=1; i<=N; i++)
     if (set[M][i]) cout << i << " ";
  cout << endl;
}

int main()
{
  cin >> M >> N;
  for (int i=1; i<=N; i++) cin >> m[i] >> c[i];
  calculate();
  return 0;
}
/*
Вход:
7
8
3 5
7 3
6 9
1 1
2 1
4 2
5 5
5 2
Изход:  10
        Взети: 3 и 4
*/
