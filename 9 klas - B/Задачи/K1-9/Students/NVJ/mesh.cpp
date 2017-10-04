#include<iostream>
#include<cmath>

using namespace std;



long int f(int a, int b)
{
    int currR, prevR=0, n=1;
    int cnt=0;
    while(n<=a)
    {
     currR=((int) ceil(n*b/a))-prevR;
     n++;
     cnt+=currR;
     prevR=currR-1;
    }
    return cnt;
}

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
     swap(a,b);
    if(a==1)
     cout<<b<<endl;
    else if(a==b)
     cout<<sqrt((a*a+b*b)/2)<<endl;
    else
    {
        long int k=__gcd(a,b);
        if(k==1)
         cout<<k*f(a/k,b/k)<<endl;
        else
         cout<<k*f(a/k,b/k)+2<<endl;
    }
    return 0;
}
