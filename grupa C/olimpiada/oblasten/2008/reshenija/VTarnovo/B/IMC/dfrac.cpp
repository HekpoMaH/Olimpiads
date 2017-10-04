#include<iostream>

using namespace std;

int main()
{
    double a,b,c; 
    long long int p,k,q=1,m,n;
    
    cin>>a>>b;
    cin>>k>>p;
    
    for(int i=1;i<p-k;i++)q=q*10;
    
    c=a/b;
    m=c*q;
    
    for(int i=1;i<k;i++)q=q/10;
    
    n=m%q;
    q=1;
    
    for(int i=1;i<p-k;i++)q=q*10;
    
    m=m+q*n;
    
    cout<<m<<'\n';
    
    return 0;
}
