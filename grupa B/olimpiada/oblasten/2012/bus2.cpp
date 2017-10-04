#include<bits/stdc++.h>
using namespace std;
unsigned to[32768],stopid[1000001];
vector<unsigned> stops;
vector<pair<unsigned,unsigned> >dist[32768];
unsigned input[32768][3];
unsigned n,a,b,i,j,bstop,astop;
priority_queue<pair<unsigned,unsigned>, vector<pair<unsigned,unsigned> >,greater<pair<unsigned,unsigned> > >cards;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b;
    a--;b--;
    for(i=0;i<n;i++)
    {
        cin>>input[i][0]>>input[i][1]>>input[i][2];
        input[i][0]--;input[i][1]--;
        stops.push_back(input[i][0]);
        stops.push_back(input[i][1]);
    }
    stops.push_back(a);stops.push_back(b);
    sort(stops.begin(),stops.end());
    stops.erase(unique(stops.begin(),stops.end()),stops.end());
    for(i=0;i<stops.size();i++)stopid[stops[i]]=i;
    astop=stopid[a];
    bstop=stopid[b];
    for(i=0;i<n;i++)
    dist[stopid[input[i][0]]].push_back(make_pair(stopid[input[i][1]],input[i][2]));
    for(i=0;i<=astop;i++)
    {
        to[i]=0;
        for(int j=0;j<dist[i].size();j++)
        cards.push(make_pair(to[i]+dist[i][j].second, dist[i][j].first));
    }
    for(i=astop+1;i<=bstop;i++)
    {
        while(!cards.empty()&&cards.top().second<i)cards.pop();
        to[i]=to[i-1]+stops[i]-stops[i-1];
        if(!cards.empty()&&cards.top().first<to[i])to[i]=cards.top().first;
        for(j=0;j<dist[i].size();j++)
        {
            cards.push(make_pair(to[i]+dist[i][j].second,dist[i][j].first));
        }
    }
    cout<<to[bstop]<<"\n";
}
