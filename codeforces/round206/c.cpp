#include<bits/stdc++.h>
using namespace std;
int n,l,r,ql,qr;
int w[100009];long long s[100009];
long long mn=999999999999,cs,csb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l>>r>>ql>>qr;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        s[i]=s[i-1]+w[i];
    }
    for(int i=0;i<=n;i++)
    {
        cs=s[i]*l+(s[n]-s[i])*r;//csb=cs;
        if(i<n-i)
        {
            cs+=(n-i-i-1)*qr;
        }
        else if(i>n-i) cs+=(i-(n-i)-1)*ql;
        mn=min(mn,cs);
        //cout<<i<<" "<<s[i]<<" "<<l<<" "<<s[n]-s[i]<<" "<<r<<" "<<cs<<" "<<csb<<" "<<mn<<endl;
    }
    cout<<mn<<endl;
}


