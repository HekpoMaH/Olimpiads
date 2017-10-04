#include <iostream>
using namespace std;

int main ()
{   
   short a; 
   short b=1; 
   short c=1;
   
   long long n;
   cin >> n;

   n = n % 600;
   if(n==0) cout << "00" << endl;
   else
     {
       short a, b=1, c=1;
   
       for(long long i=3; i<=n; i++)
       { a = b; b = c; 
         c = (a+b) % 100;
       }  
       if(c<10) cout << 0;
       cout << c << endl; 
     }
     
   return 0;
}
