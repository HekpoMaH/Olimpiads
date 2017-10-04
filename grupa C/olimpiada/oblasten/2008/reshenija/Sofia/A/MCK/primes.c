#include <stdio.h>

#define PRIME_NUMBERS_COUNT 5133

int a[PRIME_NUMBERS_COUNT];

void prime()
{
     unsigned long long i, j;
     unsigned long long n = 1;
     unsigned long long e = 0;
     a[0] = 2;

     for(i = 3; i < 50000; i++)
     {
           for(j = 0; j < n; j++)
           {
               if (!(i % a[j])) {e = 1; break;}
           }
           if (e == 0)
           {
               a[n] = i;
               n++;
           }
           else e = 0;
     }

     return;
}

unsigned long long calc_p(unsigned long long n)
{
    unsigned long long i = 0;

    for(i = 0; i < PRIME_NUMBERS_COUNT; i++)
    {
        if (a[i] > n) return (a[i]);
    }
}

unsigned long long sum(unsigned long long n, unsigned long long i, unsigned long long p)
{
    unsigned long long c = 0;

    if (n == 0) return (1);

    while (a[i] <= n)
    {
        c += sum(n - a[i], i, p);
        c = c % p;
        i++;
    }

    return (c);
}

unsigned long long calc_s(unsigned long long n, unsigned long long p)
{
    unsigned long long i;
    unsigned long long c = 0;

    i = 0;
    while ((a[i] * 2) <= n)
    {
        c += sum(n - a[i], i, p);
        c = c % p;
        i++;
    }

    return (c);
}

int main(int argc, char* argv[])
{
    int n;
    unsigned long long p, s;

    prime();
    scanf("%d", &n);
    p = calc_p(n);
    s = calc_s(n, p);
    s = s % p;
    printf("%lld", s);

    return (0);
}
