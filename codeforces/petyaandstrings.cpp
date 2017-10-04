#include<iostream>
#include<string>
using namespace std;
string a,b;
int main()
{
    cin>>a;
    cin>>b;
    for(int i=0;i<a.size();i++)a[i]=tolower(a[i]);
    for(int i=0;i<b.size();i++)b[i]=tolower(b[i]);
    //cout<<a<<" "<<b<<endl;
    if(a==b)cout<<0<<endl;
    if(a<b)cout<<-1<<endl;
    if(a>b)cout<<1<<endl;
    return 0;
}
