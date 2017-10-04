#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
int n;int k;
set<long long> s;
int x;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>x,s.insert(x);
    set<long long>::iterator it;
    if(k!=1)
    for(it=s.begin();it!=s.end();it++)s.erase(k*(*it));
    cout<<s.size()<<endl;
}

