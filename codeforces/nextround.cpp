#include<iostream>
using namespace std;
long long n,k,a[66],i;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0||(i>k&&a[k]>a[i]))break;
    }
    cout<<i-1<<endl;
    return 0;
}