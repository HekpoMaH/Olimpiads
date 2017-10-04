#include<bits/stdc++.h>
using namespace std;
string s;
long long f1,f2;
long long pv;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)if(s[i]=='^')pv=i;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='^')break;
        if(s[i]>='0'&&s[i]<='9')f1+=(pv-i)*(s[i]-'0');
    }

    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='^')break;
        if(s[i]>='0'&&s[i]<='9')f2+=(i-pv)*(s[i]-'0');
    }
    if(f1>f2)cout<<"left"<<endl;
    if(f1<f2)cout<<"right"<<endl;
    if(f1==f2)cout<<"balance"<<endl;
    return 0;
}
