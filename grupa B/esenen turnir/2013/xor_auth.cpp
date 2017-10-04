#include <iostream>
#include <algorithm>
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
long long mx(long long cnt, long long lo,long long hi,long long &from)
{if (cnt & 1)
 {long long m1=zor(hi-cnt,cnt),m2=zor(hi-cnt+1,cnt);
  if (m1>m2){from=hi-cnt;return m1;}
  from=hi-cnt+1;return m2;
 }
 //even count
 long long r=lo^hi, m=1,mask;
 long long f,M,last,a;
 while (m<=r) m<<=1;
 mask=(~(m-1))&hi;
 m>>=1;
 m|=mask;
 last=(cnt&3)?0:1;
 lo=max(lo,m-cnt+1);
 hi=min(hi,m+cnt-1);
 if (hi&1) hi--;
 if (!(lo&1)) lo++;
 M=(lo^(lo+cnt-1))^last;
 from=lo;
 for (f=lo+2;f<=hi-cnt+1;f+=2)
 {a=(f^(f+cnt-1))^last;
  if (a>M){M=a;from=f;}
 }
 return M;
}
int main()
{long long a,b,n,f;
 cin>>a>>b>>n;
 cout<<mx(n,a,b,f)<<endl;
 //cout<<zor(4,)<<endl;
 return 0;
}

