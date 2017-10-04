#include<iostream>
#include<string>
using namespace std;
long long n,br,c;
int main()
{
    cin>>n;
    while(n!=0)
    {
        c=n%10;
        if(c==4||c==7)br++;
        n/=10;
    }
    //cout<<br<<endl;
    if(br==0){cout<<"NO"<<endl;return 0;}
    while(br!=0)
    {
        c=br%10;
        if(c!=4&&c!=7){cout<<"NO"<<endl;return 0;}
        br/=10;
    }
    cout<<"YES"<<endl;
    return 0;
}