#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,a[1002];
int main()
{
    cin>>n;
    for(int i=2;i<=n;i++)a[i]=i-1;
    //swap(a[1],a[n]);
    a[1]=n;
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
