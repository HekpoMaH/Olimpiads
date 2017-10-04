#include<iostream>
using namespace std;
int n,a,b,br;
bool isl(int k)
{
    while(k!=0)
    {
        if(k%10!=4&&k%10!=7)return false;
        k/=10;
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(isl(i)==true&&n%i==0){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
    return 0;
}
