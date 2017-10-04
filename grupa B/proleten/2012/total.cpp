#include<bits/stdc++.h>
using namespace std;
string s;
long long sum;
long long getsum(string x)
{
    long long re=0;
    for(int i=0;i<x.size();i++)re=re*10+x[i]-'0';
    return re;
}
int main()
{
    cin>>s;
    int szi=1<<(s.size());
    string s2;
    for(int i=1;i<szi;i++)
    {
        s2="";
        for(int j=0;j<s.size();j++)
        {
            if((1<<j)&i)s2+=s[j];
        }
        sum+=getsum(s2);
    }
    cout<<sum<<endl;
}
