#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[103],n,xr,mx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        xr=0;
        for(int j=i;j<=n;j++)
        {
            xr=0;for(int k=i;k<=j;k++)xr^=a[k];
            mx=max(mx,xr);
        }

    }
    cout<<mx<<endl;
    return 0;
}
