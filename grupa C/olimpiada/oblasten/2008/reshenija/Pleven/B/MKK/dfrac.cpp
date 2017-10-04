#include<iostream>
using namespace std;
long a,b,p;
unsigned long long k;
int main()
{ cin>>a>>b>>k>>p;
  long ok=0;
  long aha=a;
  do
   { if(aha<b)
      ok=1;
     else
      { aha%=b;
      } 
   }while(ok!=1);
  aha*=10;
  for(int i=1; i<=k-1; i++)
   { aha%=b;
     aha*=10;
   }
  for(int i=1; i<=p; i++)
   { long x;
     x=aha/b;
     aha%=b;
     cout<<x;
     aha*=10;
   } 
  cout<<endl;
  return 0;
} 
