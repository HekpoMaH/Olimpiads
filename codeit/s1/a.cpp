#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,mn=999999,mx;
string s;
int main()
{
    freopen ( "class.in" , "r" , stdin ) ;
    freopen ( "class.out" , "w" , stdout ) ;
    fin>>n;
    for(int i=1;i<=n;i++)fin>>s,mp[s]++;
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        mn=min(mn,it->second);
        mx=max(mx,it->second);
    }
    fout<<mx<<" "<<mn<<endl;
}
