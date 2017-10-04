#include<iostream>
#include<string>
using namespace std;
int n,a,b,tram,mx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        tram-=a;tram+=b;
        mx=max(mx,tram);
    }
    cout<<mx<<endl;
    return 0;
}
