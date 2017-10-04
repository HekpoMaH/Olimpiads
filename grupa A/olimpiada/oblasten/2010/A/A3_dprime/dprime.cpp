#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long card;

bool isPrime(card a)
{if (a==1) return false;
 if (a==2) return true;
 if (!(a&1)) return false;
 card s=(card)ceil(sqrt(a));
 card t=3;
 while (t<=s)
 {
     if (!(a%t)) return false;
     t+=2;
 }
 return true;
}

char binDigCnt(card a)
{char c=0;
 card m=1;
 if (!a) return 1;
 while (m && a>=m) {c++;m<<=1;}
 return c;
}

void Erato(card start, card end, bool *s)
{if (!(end & 1)) end--;
 card p,i,n,d=((end-start)>>1)+1;
 card t=(card)ceil(sqrt(end));;
 for (i=0;i<d;i++) s[i]=true;
 for (p=3;p<=t;p+=2) if (isPrime(p))
 {
     for (i=0;i<p;i++) if (!((start+2*i)%p)) break;
     if (i>=d) continue;
     if (p<start) s[i]=false;
     n=i+p;
     while (n<d) {s[n]=false;n+=p;}
 }
}

bool isPrimeErato(card x, card start, bool *s)
{if (x==1) return false;
 if (x==2) return true;
 if (!(x&1)) return false;
 return s[(x-start)>>1];
}

char isDPrimeComb(card start,card end,
                  card a,card b,char ca, char cb,
                  card ErStart,bool *Er)
{card c;
 if (a==b) return 0;
 c=(a<<cb)|b;
 if (c<start || c>end) return 0;
 if (ca<=cb)
 {if (isPrime(c)) return 1;
  return 0;
 }
 if (isPrimeErato(c>>ca,ErStart,Er) &&
     isPrimeErato(c&(((card)1<<ca)-1),ErStart,Er)) return 0;
 if (isPrime(c)) return 1;
 return 0;
}

card makeDPrimes(card start,card end)
{if (start<10) start=10;
 if (!(start&1)) start++;
 if (!(end&1)) end--;
 if (start>end) return 0;
 card cnt=0;
 bool *Er;
 card ErStart,ErEnd,L,R;
 char ns=binDigCnt(start),ne=binDigCnt(end);
 char nL=ns>>1;
 char nR=ns-nL;
 ErStart=((card)1<<(nL-1))+1;
 ErEnd=((card)1<<(ne-(ne>>1)))-1;
 Er=new bool[((ErEnd-ErStart)>>1)+1];
 Erato(ErStart,ErEnd,Er);
 card stL=((card)1<<(nL-1))+1;
 if (stL==3) stL--;
 card stR=((card)1<<(nR-1))+1;
 card enL=((card)1<<nL)-1;
 card enR=((card)1<<nR)-1;
 do
 {for(L=stL;L<=enL;L+=((L==2)?1:2))
   if (isPrimeErato(L,ErStart,Er))
    for (R=(nL==nR)?((L==2)?L+1:L+2):stR;R<=enR;R+=2)
    {if (isPrimeErato(R,ErStart,Er))
      {cnt+=isDPrimeComb(start,end,L,R,nL,nR,ErStart,Er);
       cnt+=isDPrimeComb(start,end,R,L,nR,nL,ErStart,Er);
      }
    }
  if (nL==nR) nR++;
  else nL++;
  if (nL+nR>ne){delete Er; return cnt;}
  stL=((card)1<<(nL-1));
  if (stL!=2) stL++;
  stR=((card)1<<(nR-1))+1;
  enL=((card)1<<nL)-1;
  enR=((card)1<<nR)-1;
 }while (true);
}

int main(void)
{card a,b;
 cin>>a>>b;
 cout<<makeDPrimes(a,b)<<endl;
 return 0;
}
