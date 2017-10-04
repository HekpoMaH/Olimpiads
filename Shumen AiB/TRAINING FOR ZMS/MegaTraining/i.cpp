#include<iostream>
#include<string>
using namespace std;
string s;
void solve()
{
    int a,b;
    int mx=0;int num=0,br=0;
    do
    {
        br++;
        cin>>a>>b;if(a==0&&b==0)break;
        if(mx<a/b&&b!=0)mx=a/b,num=br;
        //cout<<mx<<
    }while(a!=0&&b!=0);
    if(mx==0)num=1102;
    cout<<num<<" "<<mx<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}

