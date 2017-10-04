#include <iostream>
#include <cstring>
#define MANY 1000
#define MX 32
using namespace std;
long long d10[19];//Powers of 10
void makeD10()//Calculate powers of 10
{d10[0]=1;
 for (int i=1;i<19;i++) d10[i]=10*d10[i-1];
}
int digCnt(long long n)//Count the digits of n
{for (int c=1;c<19;c++) if (n<d10[c]) return c;
 return 19;
}
int sumDig(long long n)//Sum up the digits of n
{int s=0;
 while (n)
 {s+=n%10;
  n/=10;
 }
 return s;
}
long long mono(int d,int c)//Create a mono of length c with digit d
{return (d10[c]-1)/9*d;
}
bool isMono(long long n)//Check if n is a mono
{return n==mono(n%10,digCnt(n));
}
//The greedy algorithm
int greedy(long long a,long long *m)
{int c=digCnt(a);
 if (isMono(a)){*m=a; return 1;}
 int d=a/d10[c-1];
 *m=mono(d,c);
 if (*m>a) {if (d==1) *m=mono(9,c-1);
            else *m=mono(d-1,c);
           }
 return 1+greedy(a-*m,&m[1]);
}
//Make a solution in m out of the digits of a
//Return the addents' count
int makeSol(long long a,long long *m)
{int c=0,i=1,dd;
 a/=10;
 while (a)
 {if ((dd=(a%10))) m[c++]=mono(dd,i);
  a/=10;
  i++;
 }
 return c;
}
//Print out the result
//First line: the integer c
//Second line: c space separated elemens of the array m
void showSol(int c,const long long *m)
{cout<<c<<endl;
 for (int i=0;i<c-1;i++) cout<<m[i]<<' ';
  cout<<m[c-1]<<endl;
}
//Try to solve the problem with monos of different size
//Return MANY if not found
//Return the mono count and the monos in m
int diffDeg(long long n,long long *m)
{long long t=9*n,a,mm[MX];
 int s=10*(t/10+1),p=MANY,sa;
 s-=t;
 do
 {a=t+s;
  sa=sumDig(a);
  if (sa<s) break;
  if (sa==s)
  {int q=makeSol(a,mm);
   if (q<p){p=q;memcpy(m,mm,p*sizeof(long long));}
  }
  s+=10;
 }while(true);
 return p;
}
//Find the next possible combination of nine-monos
//Creates the next combination in reversed alphabetic order
//n - maximal addent count
//cnt (I/O): current/next addents' count
//sum (I/O): current/next addents' sum
//a (I/O): current/next distribution
//lim: upper limit for each distribution element
//Returns true if the next distribution created
bool nextCnt(int N,int n,int *cnt, long long *sum, int *a,int *lim)
{int i;
 i=0;
 //Find the first which has not reched its upper limit
 while (i<N && a[i]>=lim[i]) {*cnt-=a[i];*sum-=a[i]*mono(9,i+2);a[i++]=0;}
 if (i>=n) return false;
 a[i]++;
 (*cnt)++;
 *sum+=mono(9,i+2);
 //If addents too many, create the first possible after the current
 if (*cnt>n)
 {*cnt-=a[0];*sum-=a[0]*mono(9,2);a[0]=0;
  *cnt-=a[1];*sum-=a[1]*mono(9,3);a[1]=0;
  i=2;
  while (i<N && (*cnt>=n || a[i]>=lim[i]))
  {*cnt-=a[i];*sum-=a[i]*mono(9,i+2);a[i]=0;
   i++;
  }
  if (i>=N) return false;
  a[i]++;
  (*cnt)++;
  *sum+=mono(9,i+2);
 }
 return true;
}
void setLim(int N,int p,int *lim)//Set the upper limits
{for (int i=0;i<N;i++)
  if (i==7) lim[i]=min(i+2,p);
  else lim[i]=min(i+1,p);
}
void solve(long long n)//Main solution
{long long res[MX],r[MX],s;
 int c,a[MX],lim[MX],i,N;
 //Find one solution
 int p=diffDeg(n,res);
 if (p==MANY) p=greedy(n,res);
 //It is optiomal, if p=1 or p=2
 if (p<3){showSol(p,res);return;}
 //Prepare combinatorics
 N=digCnt(n);
 setLim(N,p,lim);
 for (i=0;i<N;i++) a[i]=0;
 s=0;
 c=0;
 while (nextCnt(N,p,&c,&s,a,lim))
 {if (s>n) break;//s is strictly increasing
  int q=diffDeg(n-s,r);
  if (q<p-c)//A better solution found
  {memcpy(res,r,q*sizeof(long long));
   for (i=0;i<N;i++) if (a[i])
    for (int j=0;j<a[i];j++) res[q++]=mono(9,i+2);
   p=q;
   setLim(N,p,lim);
  }
 }
 showSol(p,res);
}
int main()
{long long n;
 cin>>n;
 makeD10();
 solve(n);
 return 0;
}
