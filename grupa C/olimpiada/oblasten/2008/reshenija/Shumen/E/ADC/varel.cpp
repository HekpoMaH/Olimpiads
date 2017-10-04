#include<iostream>
using namespace std;
int main ()
{
    int v,k,n,kl,i;
    char z;
    cin>>v>>k>>n;
    kl=v;
    for(i=1;i<=n;i++)
    {
        cin>>z;
        if(z=='+')kl+=k;
        if(z=='-')kl-=k;
    }
    cout<<kl<<endl;
}
 
