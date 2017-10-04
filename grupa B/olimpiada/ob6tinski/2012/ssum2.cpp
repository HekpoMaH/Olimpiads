#include<bits/stdc++.h>
using namespace std;
int x;
bool ip(int num)
{
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)return false;
    }
    return true;
}
int main()
{
    cin>>x;
    int ans=0;
    for(int i=2;i<=x/2;i++)
    {
        if(ip(i)==true&&ip(x-i)==true)ans++;
    }
    cout<<ans<<endl;
}
