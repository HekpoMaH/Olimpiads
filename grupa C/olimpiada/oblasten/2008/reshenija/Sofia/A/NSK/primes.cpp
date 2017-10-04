#include <iostream>
#include <cmath>
#define MAXN 8192
#define MAXM 65536
using namespace std;
bool isprime(int n)
{
    int i = 2;
    if (n == 2) return true;
    while (i <= sqrt(n))
    {
        if (n % i == 0) return false;
        i++;
    }
    return true;
}
long long n, r;
int primes[MAXN];
long long pc = 0;
long long data[MAXM];
long long next = 0;
int main()
{
    cin >> n;
    if (n <= 3) { cout << "0" << endl; return 0; }
    // initialize primes array
    for (int i = 2; i <= n; i++) if (isprime(i)) primes[pc++] = i;
    for (int i = n+1; i <= MAXM; i++) if (isprime(i)) { next = i; break; }
    for (int i = 0; i < pc; i++)
    {
        data[primes[i]]++;
        for (int j = 0; j <= n; j++) if (data[j] && j+primes[i] <= n) data[j+primes[i]] += data[j];
        if (i % 66 == 0) for (int l = 2; l <= n; l++) data[l] %= next;
    }
    int answ = data[n];
    if (isprime(n)) answ--;
    cout << answ % next << endl;
    //system("pause");
    return 0;
}
