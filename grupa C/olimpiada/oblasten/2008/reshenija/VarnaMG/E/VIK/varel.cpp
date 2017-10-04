#include <iostream>
using namespace std;
int main ()
{
    int V,K,N,i,n,b;
    char d,f,a[51];
    cin>>V;
    cin>>K;
    cin>>N;
    d='-';
    f='+';
for (i=0;i<N;i++)
    {
        cin>>a[i];
      if (a[i]==d)
       {
       b=V-K;
       V=b;
       }
      else
    { 
        b=V+K;
        V=b;
    }
} 
if (b>0)
cout<<b<<endl;
return 0;
}
