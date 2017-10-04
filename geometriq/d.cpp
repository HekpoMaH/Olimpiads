#include<bits/stdc++.h>

using namespace std;
typedef pair<long long,long long> pairll;
int n;
pairll pnts[10009];
set<pairll> box;
long long best;
bool compx(pairll a,pairll b)
{
    return a.second<b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>pnts[i].second>>pnts[i].first;
    sort(pnts,pnts+n,compx);
    best=1500000000;
    box.insert(pnts[0]);
    int left=0;
    for(int i=1;i<n;i++)
    {
        while(left<i&&pnts[i].second-pnts[left].second>best)box.erase(pnts[left++]);
        for(typeof(box.begin()) it=box.lower_bound(make_pair(pnts[i].first-best, pnts[i].second-best));it!=box.end() && pnts[i].first+best>=it->first; it++)
        best = min((long long)best, (long long)(pow(pnts[i].first - it->first,2.0)+pow(pnts[i].second - it->second,2.0)));
        box.insert(pnts[i]);
    }
    printf("%.2lf\n",sqrt(best));
}
