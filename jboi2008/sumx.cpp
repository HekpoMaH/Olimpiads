#include<bits/stdc++.h>
using namespace std;
const int nmax=1000009;
int a[nmax];
int n,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++)cin>>a[i],s.insert(a[i]);
    cin>>x;
    int br=0;
    for(int i=1;i<=n;i++)if(s.find(x-a[i])!=s.end())br++;
    cout<<br/2<<"\n";

}
