#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    long long x=3%m,res=1;
    while(n!=0)
    {
        if(n&1)res=res*x%m;
        n>>=1;
        x=x*x%m;
    }
    cout<<(res+m-1)%m<<endl;
    return 0;
}