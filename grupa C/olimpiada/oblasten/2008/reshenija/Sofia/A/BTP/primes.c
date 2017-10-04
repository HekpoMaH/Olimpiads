#include <stdio.h>
#include <math.h>

int primes[6000];
int br,n;
int res=0;
int F[50005];

char IsPrime(int p)
{
     if (p == 2) return 1;
     int i;
     for (i=2;i<=sqrt(p);++i) 
         if (p%i==0) return 0;
     return 1;
}

void precalc()
{
     int i;
     for (i=2;i<50022;++i) 
         if (IsPrime(i)) primes[br++] = i;
}

void solve()
{
     int i,j,p;
     for (i=0;i<br;++i) 
         if (primes[i] > n) {
            p = primes[i];
            break;
            }
     F[2] = F[3] = 1;
     for (i=4;i<=n;++i)
         for (j=0;j<br;++j) {
             if (primes[j] <= i-primes[j] && i-primes[j] >= 2) F[i] = (F[i] + F[i-primes[j]])%p;
             if (i-primes[j] < 2) break;
             }
}

int main()
{
    scanf("%d",&n);
    precalc();
    solve();
    printf("%d\n",F[n]);
    return 0;
}
