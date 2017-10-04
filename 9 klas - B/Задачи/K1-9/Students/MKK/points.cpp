#include<iostream>
using namespace std;
long n,k,apf[64];
int main()
{ cin>>n>>k;
  if(n==1)
   { cout<<0<<endl;
   }
  if(n==2)
   { cout<<1<<endl;
   } 
  if(n>2)
   { apf[1]=1;
     for(int i=2; i<=n; i++)
      { for(int j=1; j<=k; j++)
         { long x=i-j;
           if(x<=0)
            break;
           apf[i]+=apf[x]; 
         }
      }
     cout<<apf[n]<<endl; 
   }
  return 0;
} 
