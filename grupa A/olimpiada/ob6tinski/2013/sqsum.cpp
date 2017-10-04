#include<bits/stdc++.h>
using namespace std;
long long find(long long s)
{
    long long a,n,p;
    for(a=10;a>1;a--)
    {
        if((2*s)%(a*a)==0)
        {
            p=2*s/(a*a)+11-11*a;
            n=p/2;
            if(p>0&&!(p&1)&&n%10&&n%10+a<=11)return n;
        }
    }
    return s;
}
int main()
{
    long long ss;
    cin>>ss;
    cout<<find(ss)<<endl;
    return 0;
}
