#include <math.h>
#include<fstream>
#include <iostream>

using namespace std;

long a[5200]={0};

void prost()
{a[0]=2;
 a[1]=3;
 int k=0,l;
 l=2;
 for(int j=5;j<50100;j++)
 {k=0;
  if (!(j%2)) k=1;
 long s=ceil(sqrt(j));
  for(int i=3;(!k)&&i<=s;i++) if (!(j%i)) k=1;
   if (!k) {a[l]=j;
            l++;
           }
 }
}

long n,c=0;
long p[5200]={0};

void solve(int i,long s)
{if(a[i]>=n) return;
 while (s<=n)
 {s+=a[i];
  p[i]++;
  if(s==n) c++;
 }
 while(p[i])
 {s-=a[i];
  p[i]--;
  solve(i+1,s);
 }
}


int main()
{prost();
 cin>>n;
 solve(0,0);
 int i;
 for(i=0;a[i]<=n;i++);
 int p=c%a[i];
 cout<<p<<endl;
 return 0;
}


