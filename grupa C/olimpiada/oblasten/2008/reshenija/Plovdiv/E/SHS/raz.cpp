#include<iostream>
using namespace std;
int main()
{long long k,l,n,x,y,i,min=1000000;
cin>>n;
for(i=1;i<=n;i++)
{
    if(n%i==0)
    {
    if(abs((n/i)-i)<min)
{
    min=abs(n/i)-i;
    k=i;
    l=n/i;
}
 }
    }  
    if(k>l)
    cout<<l<<" "<<k<<endl;
    else
    cout<<k<<" "<<l<<endl;
return 0;
    }
