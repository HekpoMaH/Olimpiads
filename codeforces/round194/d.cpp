#include<bits/stdc++.h>
using namespace std;
int used1[1009],used2[1009],br;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        used1[x]=used2[y]=1;
    }
    if(n%2==1&&used1[n/2+1]==0&&used2[n/2+1]==0)used2[n/2+1]=1;
    for(int i=2;i<n;i++)if(used1[i]==0)br++;
    for(int j=2;j<n;j++)if(used2[j]==0)br++;
    cout<<br<<endl;
}
