#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned char Byte;
class Mono
{Byte code;
 void setMono(Byte d,Byte c){code=(c<<4)|d;}
 public:
 Mono (void) {code=0;}
 Mono (Byte d,Byte c=1){setMono(d,c);}
 bool isSet()const {return !code;}
 Byte getDig()const {return code?code&0x0F:0;}
 Byte getCnt()const {return code?code>>4:0;}
 operator long long () const
 {long long t=0;
  Byte d=getDig(),c=getCnt();
  for (Byte i=0;i<c;i++) t=10*t+d;
  return t;
 }
 long long operator +(long long a) const
 {return a+(long long)*this;
 }
 long long operator +(const Mono &a) const
 {return (long long)*this+(long long)a;
 }
 Mono &operator ++()
 {Byte d=getDig(),c=getCnt();
  if (d<9) setMono(d+1,c);
  else setMono(1,c+1);
  return *this;
 }
 Mono operator ++(int)
 {return ++(*this);
 }
};
typedef struct {Byte cnt; Mono m[8];} State;
State res;
long long operator +(long long a,const Mono &m)
{return m+a;
}
ostream &operator<<(ostream &os, Byte b)
{os<<(int)b;
 return os;
}
ostream &operator<<(ostream &os,const Mono& a)
{Byte cnt=a.getCnt(),dig=a.getDig();
 for (int i=0;i<cnt;i++) os<<dig;
 return os;
}
void dp(long long N)
{State *s=new State[N+1];
 for (long long i=1;i<=N;i++) s[i].cnt=0xFE;
 Mono m(1);
 long long t;
 while ((t=(long long)m)<=N)
 {s[t].cnt=1;
  s[t].m[0]=m;
  ++m;
 }
 if (s[N].cnt!=0xFE){res=s[N];return;}
 for (long long i=1;i<=N;i++) if (s[i].cnt==0xFE)
  for (m=Mono(1);(t=(long long)m)<i;++m)
  {Byte c=min(s[i].cnt,s[i-t].cnt);
   if (c<s[i].cnt){memcpy(s[i].m,s[i-t].m,c);
                   s[i].m[c]=m;
                   s[i].cnt=c+1;
                   if (c==1) break;
                  }
  }
 res=s[N];
 delete []s;
}
int main()
{long long n;
 cin>>n;
 dp(n);
 cout<<res.cnt<<endl;
 for (int i=0;i<res.cnt-1;i++) cout<<res.m[i]<<' ';
 cout<<res.m[res.cnt-1]<<endl;
 return 0;
}
