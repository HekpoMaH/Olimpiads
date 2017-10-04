#include <iostream>
#include <math.h>
using namespace std;
int a[10],n,m,ans; bool u[10];

void  print()
{int i;  bool f=true;   
 for (i=1;i<=n-1;i++) 
   if (abs(a[i]-a[i+1])>m) f=false;
   if (f) ans++;
}

int  permut(int i)
{int k;
 if (i>n)print();
 for (k=1;k<=n;k++)
  {if (!u[k])
     {u[k]=true;a[i]=k;permut(i+1);
      u[k]=false;
     }  
  }
 }

int main()                                                                                         
{int i; 
 cin>>n>>m;
 permut(1);
 cout<<ans<<endl;
 return 0;
}

