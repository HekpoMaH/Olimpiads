#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> > ots;
vector<pair<int,int> > ans;
int n,x,y;
bool cmp(pair<int,int> x,pair<int,int> y)
{
    if(x.second<y.second)return true;
    if(x.second>y.second)return false;
    if(x.first<y.first)return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x>y)swap(x,y);
        ots.push_back(pair<int,int>(x,y));
    }
    sort(ots.begin(),ots.end(),cmp);
    /*for(int i=0;i<ots.size();i++)
    {
        cout<<ots[i].first<<" "<<ots[i].second<<endl;
    }*/
    ans.push_back(ots[0]);
    int fl;
    for(int i=1;i<ots.size();i++)
    {
        fl=1;
        for(int j=ans.size()-1;j>=0;j--)
        {
            if(ots[i].first<ans[j].second){fl=0;break;}
        }
        if(fl==1)ans.push_back(ots[i]);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}