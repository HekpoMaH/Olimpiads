#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n,m;
int fb[10000],x,y,mn,mni,a[1009][1009],bd[1009][1009],dep[1009];
int used[1009];
vector<pair<int,int> >ans;
void build(int idx)
{
    for(int i=1;i<=n;i++)
    {
        if(a[idx][i]==0&&idx!=i&&used[i]==0)ans.push_back(make_pair(idx,i)),bd[i][idx]=bd[idx][i]=1,used[i]=1,dep[i]=dep[idx]+1;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;a[x][y]=a[y][x]=1;
        fb[x]++;fb[y]++;
    }
    while(1)
    {
        mn=9999999;
        for(int i=1;i<=n;i++)
        {
            if(fb[i]<mn&&dep[i]<2)mn=fb[i],mni=i;
        }
        build(mni);used[mni]=1;
        fb[mni]=99999999;
        if(mn==9999999)break;

    }
    int sgw=0;
    cout<<ans.size()<<endl;
        for(int i=0;i<n-1;i++)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }

}

