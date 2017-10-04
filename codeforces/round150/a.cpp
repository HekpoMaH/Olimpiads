#include<iostream>
#include<vector>
using namespace std;
int n,k;
int a[100],segments[10000];
vector<int> c[100];
int main()
{
    cin>>n>>k;for(int i=1;i<=n*k;i++)segments[i]=1;
    for(int i=1;i<=k;i++)cin>>a[i],c[i].push_back(a[i]),segments[a[i]]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n*k;j++)
        {
            if(segments[j]==1&&c[i].size()<n)c[i].push_back(j),segments[j]=0;
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<c[i].size()-1;j++)cout<<c[i][j]<<" ";
        cout<<c[i][c[i].size()-1]<<endl;
    }
    return 0;
}
