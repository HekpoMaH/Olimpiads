#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
long long x,y,p,q,n,mx;
long long a[100009];
map<long long,long long> m;
set<long long> ::iterator it;
set<long long> s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),m[a[i]]++,s.insert(a[i]);
    for(it=s.begin(); it!=s.end(); it++)
    {
        m[(*it)+1]+=m[(*it)]/2;
        if(m[(*it)]/2!=0)s.insert((*it)+1);
        mx=max(mx,((*it))+1);
        m[(*it)]%=2;
    }
    for(it=s.begin(); it!=s.end(); it++)
    {
        if(m[*it]!=0)p++;
    }
    cout<<abs(mx-p)<<endl;
}


