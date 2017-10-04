#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int> >v;
int used[200],used2[200];
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<n+m-1<<endl;
    for(int i=1;i<=m;i++)cout<<1<<" "<<i<<endl;
    for(int j=2;j<=n;j++)cout<<j<<" "<<1<<endl;
}
