#include <iostream>

using namespace std;

unsigned int primes_len = 0;

unsigned int *primes;

unsigned int n;
unsigned Sn = 0;

void fillPrimes() {
     unsigned int p = 1;
     int i;
     bool isPrime = true;
     do {
         p++;
         isPrime=true;
           for (i = 0; i<primes_len; ++i) {
               if (p % primes[i] == 0) {
                     isPrime = false;
                     break;
               }
           }
           if (isPrime) {
              primes[primes_len++]=p;
           }
     } while (p <= n);
}

int g = 0;

unsigned int **dp_array;

int findSn(int mn, int g) {
    int result = 0;
    //if (dp_array[mn][g]>0) return dp_array[mn][g];
     if (mn == 0) {
        return 1;
     }
     for (int i = g; (primes[i]<=mn) && (i<primes_len); ++i) {
         int nn = findSn(mn-primes[i], i);
         if (nn > 0) {
                result+=nn;
         }
     }
     //dp_array[mn][g]=result;
     return result;
}


int main() {
    cin >> n;
    primes = new unsigned int[n];
    
    fillPrimes();
    //cout << "Start counting\n";
    
    g = 0;
    Sn = findSn(n, 0);
    //cout << "SN:" << Sn << "\n";
    //cout << "result:";
    cout << (Sn%primes[primes_len-1]);
}
    
    
