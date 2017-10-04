#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;
int n;
set<int> s[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x,k;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>k;
        if(s[k].find(x-1)==s[k].end()&&x!=0)
        {
            cout<<"NO"<<"\n";
            return 0;
        }
        else s[k].insert(x);
    }
    cout<<"YES\n";
}
