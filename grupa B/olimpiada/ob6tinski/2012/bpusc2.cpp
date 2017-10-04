#include<bits/stdc++.h>
using namespace std;
string a,b;
int ans[100];
void sum()
{
    int zapr=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        ans[i]=zapr+a[i]-'0'+b[i]-'0';zapr=0;
        if(ans[i]>=10)zapr=1,ans[i]-=10;;
    }
    if(zapr!=0)cout<<zapr;
    for(int i=0;i<a.size();i++)cout<<ans[i];cout<<endl;
}
int main()
{
    cin>>a;
    b=a;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    //cout<<a<<" "<<b<<endl;
    if(a[0]=='0')for(int i=1;i<a.size();i++)if(a[i]!='0'){swap(a[0],a[i]);break;}
    sum();
}
