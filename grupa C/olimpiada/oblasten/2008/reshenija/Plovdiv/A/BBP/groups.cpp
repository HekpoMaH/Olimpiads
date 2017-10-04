#include <iostream>
#include <iomanip>
#include <vector.h>
#include <cmath>
using namespace std;
double a[500];
double s[500];
double d[500];


int main()
{
   int n, p, k;
   double sum=0;
   cin>>n>>p;
   int t;
   k = (n%p)?((n/p)+1):((n/p)+2);
   for(int i=0; i<n; i++)
     cin>>a[i];
   for(int i=0; i<n; i++)
     s[i/k]+=a[i];
   for(int i=0; i<n/k; i++)
     s[i]/=k;
   for(int i=n/k; i<p; i++)
     s[i]/=n%k;
   for(int i=0; i<n; i++)
   { a[i]-=s[i/k];
     a[i]*=a[i];
   }
   for(int i=0; i<n; i++)
     d[i/k]+=a[i];
   for(int i=0; i<p; i++)
     sum+=d[i];
   cout<<fixed<<setprecision(4)<<sum<<"\n";
  // system("pause");
   return 0;
   
}
