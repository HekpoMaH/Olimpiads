#include<iostream>
using namespace std;
int main ()
{
    long a,b;
    long long k;
    int p;
    cin>>a>>b>>k>>p;
    int n=k+p;
    int c[n];
    c[0]=10/b;
    int q=10%b;
    for(int i=1;i<n;i++)
    {c[i]=(10*q)/b;q=(10*q)%b;}
    for(int i=k-1;i<n-1;i++)
    {cout<<c[i];}
    cout<<endl;
    return 0;
}
    
    
