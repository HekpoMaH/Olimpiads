#include <iostream>
using namespace std;
long long zor(long long start,long long len)
{long long m,t; 
 if (start & 1)
 {t=start+len-(len & 3);
  if (t>=start+len) t-=4;
  m=start;
 }
 else
 {t=start+len-1-(len & 3);
  m=0;
 }
 for (long long i=t+1;i<start+len;i++) m^=i;
 return m;
}
long long mx1_1(long long cnt, long long lo,long long hi,long long &from)
{long long M,m;
 from=lo;
 M=zor(lo,cnt);
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
 cout<<mx1_1(n,a,b,f)<<endl;
 return 0;
}
