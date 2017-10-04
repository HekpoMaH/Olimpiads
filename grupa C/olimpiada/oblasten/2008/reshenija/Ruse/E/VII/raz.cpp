#include<iostream>
using namespace std;
int main ()
{
    long d=0,f=0,k,i,n,a,b,m;
    cin>>n;
    k=n;
    m=n;
    for(i=1;i<=n;i++)
    {
                 a=i;
                 b=n;
                 if(n%a==0)b=n/a;
                 if(abs (a-b)<m) {m=abs(a-b);d=a;f=b;}
                  
                     }
   
                     cout<<d<<" "<<f<<endl;
                     return 0;
                     }
                     
