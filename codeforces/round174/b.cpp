#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll p;ll br;
string s;
ll a,ii,f;
int main()
{
    cin>>p;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')a++;
        if(s[i]=='F')f++;
        if(s[i]=='I')ii++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')if(ii==0)br++;
        if(s[i]=='F')continue;
        if(s[i]=='I')if(ii==1)br++;
    }cout<<br<<endl;
}

