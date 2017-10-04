#include<iostream>
#include<string>
using namespace std;
int n,a,b,c,sa,sb,sc;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        sa+=a;sb+=b;sc+=c;
    }
    if(sa==0&&sb==0&&sc==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}