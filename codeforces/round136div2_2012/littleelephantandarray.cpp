#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
long long n,m,a,l,r,x,y;
map<int,int> mp[10002];
map<int,int>::iterator it;
int br;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        mp[i]=mp[i-1];
        mp[i][a]++;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        br=0;
        for(it=mp[r].begin();it!=mp[r].end();it++)
        {
            x=it->first;y=it->second;
            y-=mp[l-1][x];
            if(x==y)br++;
        }
        cout<<br<<endl;
    }
    return 0;
}
