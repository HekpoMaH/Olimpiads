#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string s;
int a[1000];
void solve()
{
    cin>>s;
    memset(a,0,sizeof(a));int l=1;
    if(s[s.size()-1]=='0'){for(int i=0;i<s.size()-2;i++)cout<<s[i];cout<<endl;}
    else
    {
        for(int i=s.size()-3;i>=0;i--){a[i]=s[i]-'0';if(l==1)a[i]++;
            if(a[i]>9)a[i]-=10;
            else l=0;
        }
        if(a[0]==0)cout<<1;
        for(int i=0;i<s.size()-2;i++)cout<<a[i];cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}
