#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long nd;
long long nod(long long x,long long y)
{
    long long r,ans=0;
    while(y!=0)
    {
        ans+=x/y;
        r=x%y;
        x=y;
        y=r;
    }
    return ans;
}
int main()
{
    cin>>a>>b;
    cout<<nod(a,b)<<endl;
}
