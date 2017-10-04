#include<iostream>
#include<map>
using namespace std;

string cm[100005],maf[100005];
int n,m;
map<string,bool> ma;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>cm[i];
        ma[cm[i]]=true;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>maf[i];
        if(ma.find(maf[i])!=ma.end())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}