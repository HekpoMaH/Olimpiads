#include<iostream>
using namespace std;
int a,b,n,k,kupeno;
int main()
{
    cin>>n>>k>>a>>b;
    if(k<=n)
    {
        while(a>=(k-1)*b)
        {
            a-=(k-1)*b;
            kupeno+=k;
        }
        while(a>=n*b)
        {
            a-=n*b;
            kupeno+=n+1;
        }
        kupeno+=a/b;
    }
    else
    {
        while(a>=n*b)
        {
            a-=n*b;
            kupeno+=n+1;
        }
        while(a>=(k-1)*b)
        {
            a-=(k-1)*b;
            kupeno+=k;
        }
        kupeno+=a/b;
    }
    cout<<kupeno<<endl;
    return 0;
}
