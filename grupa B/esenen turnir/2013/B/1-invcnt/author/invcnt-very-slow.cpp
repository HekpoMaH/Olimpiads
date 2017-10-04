// Есенен турнир по информатика - 2013
// Задача: Брой на инверсиите
// Автор: Стоян Капралов
// Много бавно решение, основано на
// директно използване на дефиницията
// n < 20000

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
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(a[i]>a[j]) cnt++;
  printf("%lld\n",cnt);

  return 0;
}
