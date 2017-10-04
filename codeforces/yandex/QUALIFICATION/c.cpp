#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long n;
long long xr,br;
int main()
{
    cin>>n;
    if(n%2==0)
    {
        cout<<(n+1)*(n/2)<<" ";
    }
    if(n%2==1)
    {
        cout<<(n)*((n-1)/2)+n<<" ";
    }
    for(int i=1;i<=n;i++)
    {
        xr^=i;
    }
    if(xr==0){cout<<0<<endl;return 0;}
    for(int i=1;i<=n;i++)
    {
        if((i^xr)<=i)br++;
    }
    cout<<br<<endl;
}
//1,1,0,1,3,3,7,1,5,3

