#include<iostream>
using namespace std;
long long n,pr=1;
int nod(int x,int y)
{
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    cin>>n;
    if(n==1)cout<<1<<endl;
    else if(n==2)cout<<2<<endl;
    else if(n%2==1)cout<<n*(n-1)*(n-2)<<endl;
    else
    {
        long long a=n,b=n-1,c=n-3;
        if(n%3!=0)cout<<a*b*c<<endl;
        else cout<<b*(n-2)*c<<endl;
    }
    //pr=n;
    //cout<<n*(n-1)*(n-2)<<endl;
    return 0;
}
