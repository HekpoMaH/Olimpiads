#include<iostream>
using namespace std;
long long x,y,p,sum;
int main()
{
    cin>>x>>y>>p;
    if(x>y)swap(x,y);
    for(long long i=x-1;i>=1;i--)
    {
        sum=(sum+i*y/x)%p;
        cout<<i*y/x<<endl;
    }
    cout<<sum<<endl;
}
