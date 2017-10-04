#include <iostream>
#include <vector.h>
#include <cmath>
//#define ulong unsigned long;
using namespace std;
unsigned long p,n;
unsigned long sm=0;
vector<unsigned long> primes;
void S(unsigned long k, unsigned long sum, unsigned long ind)
{
    for(unsigned long i=ind; i<primes.size(); i++)
      if(sum+primes[i]==k)
      {
        sm++;
      }
      else
        if((sum+primes[i])<k)
          S(k,sum+primes[i],i);
        else
          return;
         
}
unsigned long put_primes(unsigned long k)
{
   unsigned long i=0;
   unsigned long index=0;
   unsigned long j;
   bool f=false;
   for(j=3;j<k+1; j++)
   {
     for(i=0;i<primes.size(); i++)
     {
       if(j%primes[i]==0)
       {
            f=true;
            break;
       }
     }
     if(!f)
       primes.push_back(j); 
     f = false;  
   }
   bool f1=false;
   f=false;
   j=k+1;
   do
   {
     for(i=0;i<primes.size(); i++)
       if(j%primes[i]==0)
       {
         f=true;
         break;
       }
     if(!f)
     {
       primes.push_back(j); 
       f1=true;
     }
     j++;
     f = false; 
   }
   while(!f1);  
      
}
int main()
{
   cin>>n;
   primes.push_back(2);
   put_primes(n);
   for(int i=0; i<primes.size(); i++)
     S(n,primes[i],i);
   cout<<sm%primes[primes.size()-1]<<"\n";
  
 return 0;
 
    
}
