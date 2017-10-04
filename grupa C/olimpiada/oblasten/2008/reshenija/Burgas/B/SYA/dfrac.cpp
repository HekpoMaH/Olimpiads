#include <iostream>
using namespace std;
#include <math.h>


int long long a ,b,k,p;
//double long long x;

int main ()
{
    cin >> a>>b;
    cin >> k>>p;
 
   
     double    v=1.0*a/b;
     do {v=v*10;
     k--;}
     while (k!=1);
 double n=v-floor(v);
 
     do 
     {int c=n*10;cout<<c;
     n=n*10-c;
     p--;
   }
     while (p>0);
    cout<<endl;
     return 0;
}
         
