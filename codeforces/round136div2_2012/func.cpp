#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int x,a[1002];
void func(int n)
{
    if(n==1)return;
    func(n-1);
    swap(a[n],a[n-1]);
}
int main()
{
    cin>>x;
    for(int i=1;i<=x;i++)cin>>a[i];
    func(x);
    for(int i=1;i<=x;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
