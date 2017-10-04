#include<bits/stdc++.h>
using namespace std;
int m,used[5009];
int a,am;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        used[a]++;
        am=max(a,am);
    }
    for(int i=1;i<=am;i++)
    {
        if(used[i]!=0)ans.push_back(i),used[i]--;
    }
    for(int i=am-1;i>=0;i--)
    {
        if(used[i]!=0)ans.push_back(i),used[i]--;
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";cout<<endl;
}
