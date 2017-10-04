#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<pair<int,int> >ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    if(n/2+n%2<=k)
    {
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<i+1+k;j++)
        {
            ans.push_back(make_pair(i,j%n));
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
}
