#include<iostream>
using namespace std;
int main ()
{
    long v,k,n,i,f;
    char c;
    cin>>v>>k>>n;
    f=v;
    for(i=1;i<=n;i++)
    {
                     cin>>c;
           if(c=='-') f-=k;
           if(c=='+') f+=k;
           }
           cout<<f<<endl;
           
                     return 0;
                     }
                     
                     
                     
    
