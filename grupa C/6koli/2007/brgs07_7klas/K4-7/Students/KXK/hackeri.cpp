#include<iostream>
using namespace std;
int main()
{
    string a;
    int pol=1,j,n,i,k=1;
    cin>>a;
    n=a.size();
    for(i=0;i<n-1;i++) if(a[i]!=a[i+1]) k=0;
    if(k==1) a+=a[0];
    else
    {
    for(i=0;i<n/2;i++)
    if(a[i]!=a[n-i-1]) pol=0;
    if(pol==1)
    for(i=1;i<n;i++)
    {
        char p=a[i];
        a+=p;
    }
    else
    for(i=n-2;i>=0;i--)
    {
        char p=a[i];
        a+=p;
    }
    }
    cout<<a<<'\n';
    return 0;
}
    
