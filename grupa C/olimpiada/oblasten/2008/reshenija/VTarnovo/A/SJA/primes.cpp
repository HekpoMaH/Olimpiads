#include <iostream>
#include <math.h>
using namespace std;

int DP[50001];
int primes[10000], cnt;
bool pr[50001];

bool prime(int n)
{
    int h = (int)sqrt(n);
    for (int i = 2; i <= h; i++)
     if (n%i == 0) return 0;
    return 1;
}
int main()
{    
    memset(pr, 1, sizeof(pr));
    pr[0] = pr[1] = 0;
    
    int N;    
    cin >> N;
    for (int i = 2; i < N; i++) if (pr[i])
    {
        primes[cnt++] = i;
        for (int j = i + i; j <= N; j += i)
         pr[j] = 0;  
    }
    int MOD;
    for (int i = N + 1;; i++)
     if (prime(i))
     {
         MOD = i;
         break;
     }
    
    DP[0] = 1;
    for (int i = 0; i < cnt; i++)
     for (int j = 0; j <= N - primes[i]; j++)
     {
         DP[j + primes[i]] += DP[j];
         if (DP[j + primes[i]] >= MOD) DP[j + primes[i]] -= MOD;
     }
    
    cout << DP[N] << endl;
    return 0;
} 
