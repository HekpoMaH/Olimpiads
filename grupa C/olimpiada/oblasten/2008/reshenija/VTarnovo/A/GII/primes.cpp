#include <iostream>
#include <cmath>
using namespace std;

int primes[6000];
int n, p;
int cnt(1);
void findPrimes();
int F[50001];

int main()
{
    int i, j;
    cin >> n;
    if (n < 4) { cout << "0" << endl; return 0; }
    primes[0] = 2;
    findPrimes();
    
    F[0] = 1;
    for (i=0;i < cnt-1;i++)
     for (j=primes[i];j <= n;j++)
     {
         F[j] += F[j-primes[i]];
         F[j] %= primes[cnt-1];
     }
    
    //for (i=0; i<=n;i++)
    // cout << F[i] << " ";
    //cout << endl;
    
    if (primes[cnt-2] == n) F[n]--;
    cout << F[n] << endl;
    //system("pause");
    return 0;
}

void findPrimes()
{
     int i(3), max, j;
     while(1)
     {
        max = (int)(sqrt(i)) + 2;
        
        for (j=3;j < max;j+=2)
         if (i % j == 0) break;
        
        if (j >= max)
        {
           primes[cnt++] = i;
           if (i > n) return;
        }
        i+=2;
     }
}
    
        
