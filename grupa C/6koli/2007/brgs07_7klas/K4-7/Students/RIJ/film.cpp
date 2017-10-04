#include<iostream>
using namespace std;
int main()
{
    unsigned long long n,b,a,min=2000000000;
    int k,u,p=0;
    cin>>k>>u>>n;
    if (k==u) {cout<<0<<endl;return 0;}
    unsigned long long l=1,r=200000000,m;
    while(l<=r)
    {
        m=(l+r)/2;
        if ((k*n+m)/(n+m)<=u)
        {
            min=m;
            p=1;r=m-1;continue;
        }
        else l=m+1;
    }
    cout<<min<<endl;
    return 0;
}
            
