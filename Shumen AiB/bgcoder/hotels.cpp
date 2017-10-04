#include<iostream>
using namespace std;
int a[102],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int br1=0,br2=0,ff;
    ff=a[n];
    for(int i=n-1;i>=1;i--)
    {
        //cout<<a[i]<<" "<<a[i-1]<<endl;
        if(a[i]>ff)br1++,ff=a[i];
    }
    br1++;
    ff=a[1];
    for(int i=2;i<=n;i++)
    {
        //cout<<a[i]<<" "<<a[i+1]<<endl;
        if(ff<a[i])br2++,ff=a[i];
    }
    br2++;
    cout<<br2<<" "<<br1<<endl;
    return 0;
}