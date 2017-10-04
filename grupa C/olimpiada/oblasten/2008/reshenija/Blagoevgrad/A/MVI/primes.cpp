#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int isprime(int p){
    if(p%2==0)return 0;
    int i=floor(sqrt(p));
    if(i%2 == 0)i++;
    for(i;i>2;i=i-2)if(p%i == 0){return 0;}
    return 1;
}

int nextprime(int k){
    //if(isprime(k))return k;
    if (k <= 1) return 2;
    else if(k == 2) return 3;

    int d;
    d=k%6;
    if(d == 0){
         if(isprime(k+1))return k+1;
         k+=6;
    }
    else if(d == 5){
         if(isprime(++k+1))return k+1;
         k+=6;
    }
    else {
         k+=(6-d);
    }
    while (1){
                if(isprime(k-1))return k-1;
                else if(isprime(k+1))return k+1;
                k+=6;
    }
    return 0;
}

int lprimes[5132];
int lprimes_size;
int sumways(int ai,int t = 0,int o=0){
    int i,r=0;
    for (i=o;i<lprimes_size;i++){
      if((t + lprimes[i]) == ai){
            return 1;      
      }
      else if ((t+lprimes[i]) > ai){
           continue;
      }
      else {
           r+=sumways(ai,t+lprimes[i],i);
      }
    }
    return r;
}
void loadlprimes(int n){
    int i=((n%2)?(n):(n-1));
    int c=0;
    for (i;i>2;i=i-2){
        if(isprime(i)){
            lprimes[c++] = i;
        }
    }
    lprimes[c++] = 2;
    lprimes_size = c;     
}
int main(int argc, char *argv[])
{

   int i,n=9;
    int p = nextprime(n);
    loadlprimes(n);
    cout << (sumways(n) % p) << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
