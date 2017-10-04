#include <iostream>
using namespace std;

int N;

int main(void)
{long long a;
 char f[10];
 int i,j,s;
 cin>>N;
 if (N==90) {cout<<12345678990LL<<endl; return 0;}
 if (N%10==0)
 {if (N%3==0) a=12334000000LL; else a=11234000000LL;
  for (i=56789;i<=98765;i++)
  {for (j=5;j<=9;j++) f[j]=0;
   s=i;
   while (s>0)
   {j=s%10;
    if (j<5) break;
    if (f[j]>0) break;
    f[j]=1;
    s=s/10;
   }
   if (s==0 && (a+10*i)%N==0){cout<<a+10*i<<endl; return 0;}
  }
 }
 if (N%9==0)
 {a=10234000000LL;
  for (i=567899;i<=998765;i++)
  {for (j=5;j<=9;j++) f[j]=0;
   s=i;
   while (s>0)
   {j=s%10;
    if (j<5) break;
    if ((j<9 && f[j]>0)||f[j]>1) break;
    f[j]++;
    s=s/10;
   }
   if (s==0 && (a+i)%N==0){cout<<a+i<<endl; return 0;}
  }
 }
 if (N%3==0) a=10233000000LL;else a=10123000000LL;
 for (i=456789;i<=987654;i++)
 {for (j=4;j<=9;j++) f[j]=0;
  s=i;
  while (s>0)
  {j=s%10;
   if (j<4) break;
   if (f[j]>0) break;
   f[j]=1;
   s=s/10;
  }
  if (s==0 && (a+i)%N==0){cout<<a+i<<endl; return 0;}
 }
 cout<<"no"<<endl;
 return 0;
}

