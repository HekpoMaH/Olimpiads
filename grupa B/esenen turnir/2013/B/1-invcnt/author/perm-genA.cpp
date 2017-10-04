// Есенен турнир по информатика - 2013
// Задача: Брой на инверсиите
// Автор: Стоян Капралов
// Генератор на случайна пермутации
//

#include <iostream>
#include <cstdlib>
using namespace std;

const int NMAX = 1000000;
int a[NMAX];

// n -брой елементи
// seed - за генератора на случайни числа
void permgen(int n, int seed)
{ srand(seed);
  for(int i=0; i<n; i++)
    a[i] = i+1;
  for(int k=n; k>1; k--)
  { int p = rand()%k;
    swap(a[p],a[k-1]);
  }
}

int main()
{ int n, seed;
  cin >> n >> seed;

  permgen(n,seed);
  cout << n << endl;
  for(int i=0; i<n-1; i++)
    cout << a[i] << " ";
  cout << a[n-1] << endl;

  return 0;
}

