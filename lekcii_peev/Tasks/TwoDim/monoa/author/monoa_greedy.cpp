#include <iostream>
using namespace std;
int digCnt(long long a)
{int c=0;
 do
 {c++;
  a/=10;
 }while (a);
 return c;
}
long long mono(int c,int d)
{long long r=0;
 for (int i=0;i<c;i++) r=10*r+d;
 return r;
}
void showRes(long long a,int n,const long long *r)
{cout<<n<<endl;
 for (int i=0;i<n-1;i++) cout<<r[i]<<' ';
 cout<<r[n-1]<<endl;
}
int solve(long long a,long long *r)
{int c=0;
 do
 {c++;
  int n=digCnt(a);
  long long d=1;
  for (int i=1;i<n;i++) d*=10;
  long long t=mono(n,a/d);
  if (t==a)
  { r[c-1]=a;
    return c;
  }
  if (t>a)
  {if (a/d==1) t=mono(n-1,9);
   else t=mono(n,a/d-1);
  }
  r[c-1]=t;
  a-=t;
 }while (true);
 return c;
}
int main()
{ long long a,r[64];
  cin>>a;
  int m=solve(a,r);
  showRes(a,m,r);
 return 0;
}
