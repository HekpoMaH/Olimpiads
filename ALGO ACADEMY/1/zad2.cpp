#include<iostream>
#include<string>
using namespace std;
string s;
int n,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)s+="*";
    cout<<s<<endl;
    for(int i=2;i<=n/2+1;i++)
    {
        s[n-br-1]='.';
        s[br]='.';
        br++;
        cout<<s<<endl;
    }
    br--;
    for(int i=n/2+1;i>=2;i--)
    {
        s[n-br-1]='*';
        s[br]='*';
        br--;
        cout<<s<<endl;
    }
    return 0;
}