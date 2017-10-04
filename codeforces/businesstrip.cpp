#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int k;
int a[13],sum;
int main()
{
    cin>>k;
    for(int i=0;i<12;i++)cin>>a[i];
    if(k==0){cout<<0<<endl;return 0;}
    sort(a,a+12);
    for(int i=11;i>=0;i--)
    {
        sum+=a[i];
        //cout<<a[i]<<" "<<sum<<endl;
        if(sum>=k){cout<<12-i<<endl;return 0;}
    }
    cout<<-1<<endl;
    return 0;
}
