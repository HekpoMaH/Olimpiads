// Есенен турнир по информатика - 2013
// Задача: Брой на инверсиите
// Автор: Стоян Капралов
// Бавно решение, основано на сортиране
// по метода на простото вмъкване
// n <= 50000 или почти подреден масив

#include <cstdio>
using namespace std;

const int NMAX = 1000000;

int a[NMAX];
int n;

int main()
{ scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&a[i]);

  long long cnt = 0;
  for(int i=1; i<n; i++)
  { int x = a[i];
    int j=i-1;
    while(j>=0 && a[j]>x)
    { a[j+1]=a[j]; j--; }
    a[j+1]=x ;
    cnt = cnt + (i-j-1);
  }
  printf("%lld\n",cnt);

  return 0;
}
