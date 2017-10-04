#include<iostream>
using namespace std;
int n;
int a[1005];
int sum,br=1,ms,mb,ps;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        //f(a[i]==a[i-1]&&a[i-1]==a[i-2])
       // {
            if(a[i]+a[i-1]+a[i-2]>ms)ms=a[i]+a[i-1]+a[i-2],mb=i-1;
        //}
        //cout<<sum<<" "<<br<<endl;

    }

    cout<<ms<<" "<<mb<<endl;
    return 0;
}
