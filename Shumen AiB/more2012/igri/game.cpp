#include<iostream>
using namespace std;
int a[102],n,xr,br1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];xr^=a[i];
        if(a[i]==1)br1++;
    }
    if(br1==n&&br1%2==0)
    {
        cout<<"Snowwhite"<<endl;
        return 0;
    }
    if(br1==n&&br1%2==1)
    {
        cout<<"Rudolff"<<endl;
        return 0;
    }
    if(xr==0)cout<<"Rudolff"<<endl;
    else cout<<"Snowwhite"<<endl;
    return 0;
}