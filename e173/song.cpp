#include<iostream>
using namespace std;
int main()
{
    long long int m,n,k;
    cin>>n>>m>>k;
    m=m+n*60;
    m=m*16;
    k=k*1024;
    if(m<=k){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl<<m-k<<endl;}
    return 0;
}
