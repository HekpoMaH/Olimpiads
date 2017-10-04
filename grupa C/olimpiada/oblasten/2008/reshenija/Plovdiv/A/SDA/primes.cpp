#include <iostream>
#include <cmath>

using namespace std;

int primes[50000];
bool isprime(int i){
    int a = static_cast<int>(sqrt(i));
    for (int j=2; j<=a; j++)
        if (i%j==0) return false;
    return true;
}

int main(){
    int s;
    cin >> s;
    int i, j=0;
    for (i=s; i>=2; --i) if (isprime(i)) {primes[j]=i; j++;}
    int num=j-1, prim=0, sum=0;
    int n, m;
    //for (int x=0; x<=num; x++) cout << primes[x];
    
    
    for (i=1; i<=num; i++)
        for (m=0; m<num; m++) {
           sum=0; 
          for (n=0; n<=num; n++){
             for (j=0; j<=i; j++)  
              { 
               if (n+m<=num)
               sum+=primes[n+m];              
               if (sum==s) prim++;           
              }
             }
           }
    
    int x=prim;
    while (!isprime(x)) x++;
    cout << prim % x;
    return 0;
}
    
