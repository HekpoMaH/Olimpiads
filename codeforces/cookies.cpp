#include<iostream>
using namespace std;
int a[101],n;
int sum,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==0&&sum%2==0)br++;
        if(a[i]%2==1&&sum%2==1)br++;
    }
    cout<<br<<endl;
    return 0;
}