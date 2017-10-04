#include<bits/stdc++.h>
using namespace std;
string s,wans;
int n;
long long ans=0;
long long teg(string a)
{
    long long re=0,st=1;
    for(int i=0;i<a.size();i++)
    {
        a[i]=tolower(a[i]);
        re+=(a[i]-'a'+1)*st;
        st*=2;
    }
    return re;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        long long tejest=teg(s);
        if(tejest>ans)
        {
            ans=tejest;
            wans=s;
        }
    }
    cout<<wans<<endl;
}
