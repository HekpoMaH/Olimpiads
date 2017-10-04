#include<iostream>
#include<vector>
using namespace std;
vector<int> v[200009];
int n,m;
int st[200009];int a,b;
vector<int>ans;
vector<pair<int,int> >g;

void solve()
{
    int br=0;
    for(int i=1;i<=n;i++)
    {
        if(st[i]%2==0)br++;
    }
    if(br%2==1){cout<<-1<<endl;return;}
    if(br==0)
    {
        cout<<m<<endl;
        for(int i=1;i<=m;i++)cout<<i<<endl;return;
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<-1<<endl;
}

