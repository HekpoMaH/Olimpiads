#include<bits/stdc++.h>
using namespace std;
int n,l;
string s;
long long ans;
void solve(int x,int end,int dir)
{
    deque<int> dq;
    while(1)
    {

        while(!dq.empty()&&dir*(x-dq.back())>l)dq.pop_back();
        ans+=dq.size();
        if(x==end)break;
        if((s[x]=='-')==(dir==1))
        {
            dq.push_front(x);
        }
        else if(!dq.empty())dq.pop_front();
        x+=dir;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    cin>>s;
    solve(0,n,1);
    solve(n-1,-1,-1);
    cout<<ans<<endl;
}
