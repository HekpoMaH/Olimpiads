#include<bits/stdc++.h>
using namespace std;
int n;
int nums[1000009],a[1000009];
long long sum=0;
set<int> s;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>nums[i],a[nums[i]]++;
    int tek=999999,br=0;
    //cout<<2*n<<"\n";
    for(int i=1;i<=1000000;i++)
    {
        if(a[i]&&a[1000000-i+1])br++;
        else
        {
            if(a[i])ans.push_back(1000000-i+1);
        }
    }
    for(int i=1;i<=1000000;i++)
    {
        if(!a[i]&&!a[1000000-i+1])
        {
            if(br)br-=2,ans.push_back(i),ans.push_back(1000000-i+1);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
}
