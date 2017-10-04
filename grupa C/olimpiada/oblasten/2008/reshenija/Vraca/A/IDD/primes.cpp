#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

typedef vector<__int32> nv;
//typedef list<__int32> nl;

nv prime_numbers;
nv stack;
//vector<nl> all;

int N;

int mets;

void MakePrimes()
{
     __int32 primes[500001];
     for(int i = 2;i<50000;++i)
     {
             if(!primes[i])
             {
                           prime_numbers.push_back(i);
                           for(int k=2*i; k < 50000; k+=i)
                                   primes[k] = 1;
             }
     }
     return;
}

int BinarySearch(int i)
{
    int first = 0, last = prime_numbers.size()-1;
     while (first <= last) {
       int mid = (first + last) / 2;  // compute mid point.
       if (i > prime_numbers[mid]) 
           first = mid + 1;  // repeat search in top half.
       else if (i < prime_numbers[mid]) 
           last = mid - 1; // repeat search in bottom half.
       else
           return mid;     // found it. return position /////
     }
     return -(first + 1);    // failed to find key
}
     
void print()
{
     for(nv::iterator itr = stack.begin(); itr != stack.end(); ++itr)
   cout << *itr << " ";
    cout << endl;
}      
     
void S(__int32 n, __int32 last=0)
{
     
    if(n == 0)
    {
         //print();
         mets++;
         return;
    }
    
    if(n < 2)
         return;
    
    int pos = 0;
    if(last)
            pos = BinarySearch(last);
            
    for(int i = pos; prime_numbers[i] <= n; ++i)
    {
            //stack.push_back(prime_numbers[i]);
            S(n-prime_numbers[i], prime_numbers[i]);
            //stack.pop_back();
    }
    
}

int main()
{
    MakePrimes();
    
    int n;
    
    cin >> n;
    
    mets = 0;
    
    S(n);
    
    int pr;
    for(int i=0; i<prime_numbers.size(); ++i)
            if(prime_numbers[i] > n)
            {
                            pr = prime_numbers[i];
                            break;
            }
    
    cout << mets % pr << endl;
    
 //   system("pause");
    return 0;
}
