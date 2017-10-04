#include<bits/stdc++.h>
using namespace std;
const int nmax=1000*1000+9;
int cut[nmax];
int n,r,c;
int ans[nmax],sz;
vector<int> divv[nmax];
int main()
{
    cin>>n>>r>>c;
    for(int i=2;i<=n*n;i++)
    {
        if(cut[i]==0)for(int j=i;j<=n*n;j+=i)cut[j]++;
    }
    divv[1].push_back(1);
    for(int i=2;i<=n*n;i++)divv[cut[i]].push_back(i);
    for(int i=1;i<=n*n;i++)
    {
        if(divv[i].size()>0)
        {
            sort(divv[i].begin(),divv[i].end());
            for(int j=0;j<divv[i].size();j++)
            {
                sz++;ans[sz]=divv[i][j];
            }
        }
    }cerr<<sz<<endl;
    cout<<ans[(r-1)*n+c]<<"\n";
}
