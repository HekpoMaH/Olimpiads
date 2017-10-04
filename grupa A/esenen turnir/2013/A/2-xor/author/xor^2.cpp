#include <iostream>
using namespace std;
long long mx2(long long cnt, long lo,long long hi,long long &from)
{long long M=-1;
 for (long long i=lo;i<=hi-cnt+1;i++)
 {long long m=i;
  for (long long j=i+1;j<i+cnt;j++) m^=j;
  if (m>M){M=m;from=i;}
 }
 return M;
}
int main()
{long long a,b,n,f;
 cin>>a>>b>>n;
 cout<<mx2(n,a,b,f)<<endl;
 return 0;
}
