// Есенен турнир по информатика - 2013
// Задача: Брой на инверсиите
// Автор: Стоян Капралов
// Бързо решение, основано
// на сортиране чрез сливане
// n <= 1000000


#include <cstdio>
#include <cstdlib>
using namespace std;

const int NMAX = 1000000;
int a[NMAX], b[NMAX];
int n;
long long cnt;

void mergesort(int a[], int p, int q)
{ if(q-p<2) return;

  int m = (p+q+1)/2;
  mergesort(a,p,m); // sort left part
  mergesort(a,m,q); // sort right part

  // merge letf and right
  for(int i=p; i<q; i++) b[i] = a[i];
  int i=p, j=m, k=p;
  while(i<m && j<q)
  { if(b[i]<b[j]) { a[k]=b[i]; i++; k++; }
    else {cnt=cnt+m-i; a[k]=b[j]; j++; k++; }
  }
  while(i<m) { a[k]=b[i]; i++; k++; }
  while(j<q) { a[k]=b[j]; j++; k++; }
}

int main()
{ scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&a[i]);

  cnt = 0;
  mergesort(a,0,n);
  printf("%lld\n",cnt);

  return 0;
}
