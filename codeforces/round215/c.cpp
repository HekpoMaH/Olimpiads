#include<bits/stdc++.h>
using namespace std;
string s;
int x[100009],y[100009],z[100009],m,l,r;
int main()
{
    cin>>s;
    cin>>m;
    for(int i=1;i<=s.size();i++)
    {
        x[i]=x[i-1];
        y[i]=y[i-1];
        z[i]=z[i-1];
        if(s[i-1]=='x')x[i]++;
        if(s[i-1]=='y')y[i]++;
        if(s[i-1]=='z')z[i]++;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        if(min(x[r]-x[l-1],min(y[r]-y[l-1],z[r]-z[l-1]))+1>=max(x[r]-x[l-1],max(y[r]-y[l-1],z[r]-z[l-1]))){cout<<"YES\n";continue;}
        if(r-l+1<=2){cout<<"YES\n";continue;}
        cout<<"NO\n";
    }
}
