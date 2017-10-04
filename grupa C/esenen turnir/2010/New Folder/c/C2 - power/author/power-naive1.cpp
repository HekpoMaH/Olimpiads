#include <iostream>
#include <cmath>
using namespace std;
long long stepen(long long a, long long n, long long m)
{
   double r=pow((double)a,(double)n);
//   cout << r << "   ";
   return ((long long int)r)%m;
}

long long int x[1000002];

int main()
{ long long int n, m, S=0;
  cin>>n; cin>>m;
  for(int i=1;i<=n;i++)
  cin>>x[i];
  for(int i=1;i<=n;i++)
  {
   //cout<<stepen(x[i],i+1,m)<<endl;
   S=(S+stepen(x[i],i+1,m))%m;
  }
  cout<<S<<endl;
}
