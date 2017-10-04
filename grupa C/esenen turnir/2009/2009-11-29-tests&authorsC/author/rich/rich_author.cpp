#include <cstdio>
#define MAXN 1001

unsigned A[MAXN], // парите в купчинките
         b,       // банковата сметка
         c,       // купчинки, получили пари от банката
         result,  // резултатът
         i, last;

int main () {
  for ( scanf("%d",&b); scanf("%d",&i)==1;  A[b]++, b=i );
  for (last=MAXN; A[--last]==0; );
  for ( i=0 ; i<=last; i++ ) if (A[i]) {
    if (result > i) b+=(result-i) * c, result=i;
    if (b<c) break;
    result=i+b/(c+=A[i]);
    b%=c;
  }
  printf("%u\n",result);
  return 0;
}
