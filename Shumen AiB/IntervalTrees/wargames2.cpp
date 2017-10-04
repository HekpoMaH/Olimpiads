#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int n,k,idx,br;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)v.push_back(i);idx=k-1;
    while(v.size()!=0)
    {
        cout<<v[idx]<<" ";
        v.erase(v.begin()+idx);
        idx+=k;cout<<idx<<endl;
        idx%=(v.size()+1);
        
    }
    cout<<endl;
}