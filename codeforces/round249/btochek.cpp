#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
map<pair<string,int>, bool> m;
string a;
int k;
long long ans;
queue<pair<string,int> > q;
void checkcur(pair<string,int> x)
{
    long long xx=0;
    for(int i=0;i<x.first.size();i++)xx=xx*10+x.first[i]-'0';
    ans=max(ans,xx);
}
int main()
{
    cin>>a>>k;
    m[mp(a,k)]=true;
    q.push(mp(a,k));
    while(!q.empty())
    {
        pair<string,int> curr,nw;
        curr=q.front();q.pop();
        checkcur(curr);
        if(curr.second==0)continue;
        for(int i=0;i<curr.first.size()-1;i++)
        {
            nw=curr;
            //if(nw.first[i]>nw.first[i+1])continue;
            swap(nw.first[i],nw.first[i+1]);nw.second--;
            if(nw.second!=-1&&m[nw]==false)
            {
                q.push(nw);m[nw]=true;
            }
        }
    }
    cout<<ans<<endl;
}
