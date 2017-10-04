#include<bits/stdc++.h>
using namespace std;
const int kmax=1009;
int k;
int n[kmax],x;
vector<int> v[kmax];
int p[kmax];
bool chek(int el,int mas)
{
    if(p[mas]>=v[mas].size())return false;
    while(v[mas][p[mas]]<el&&p[mas]<v[mas].size())p[mas]++;
    if(v[mas][p[mas]]==el)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    for(int i=1;i<=k;i++)cin>>n[i],p[i]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n[i];j++)
        {
            cin>>x;
            v[i].push_back(x);
        }
        sort(v[i].begin(),v[i].end());
    }
    int l;
    for(int i=0;i<v[1].size();i++)
    {
        l=1;
        for(int j=2;j<=k;j++)
        {
            if(chek(v[1][i],j)==false){l=0;break;}
        }
        if(l){cout<<v[1][i]<<"\n";return 0;}
    }
    cout<<"x\n";
}
