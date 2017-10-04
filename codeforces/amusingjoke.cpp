#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a,b,z;
int main()
{
    cin>>a;
    cin>>b;
    cin>>z;
    a+=b;
    sort(a.begin(),a.end());
    sort(z.begin(),z.end());
    if(a==z)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
