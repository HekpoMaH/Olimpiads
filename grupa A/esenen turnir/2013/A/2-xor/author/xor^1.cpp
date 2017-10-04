#include <iostream>
using namespace std;
long long mx1(long long cnt, long long lo,long long hi,long long &from)
{long long M=0,m;
 from=lo;
 for (long long i=lo;i<lo+cnt;i++) M ^= i;
 if (cnt==hi-lo+1) return M;
 m=M;
 for (long long i=lo+1;i<=hi-cnt+1;i++)
 {m=m^(i-1)^(i+cnt-1);
  if (m>M){M=m;from=i;}
 }
 return M;
}
int main()
{long long a,b,n,f;
 cin>>a>>b>>n;
 cout<<mx1(n,a,b,f)<<endl;
 return 0;
}
