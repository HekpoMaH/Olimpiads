#include <iostream>
using namespace std;
long long stepen(long long a, long long n, long long m)
{ long long f=1;
    for(int i=1;i<=n;i++) f=(f*a)%m;
    return f%m;
}

long long int x[1000002];

int main()
{ long long n, m, S=0;
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
