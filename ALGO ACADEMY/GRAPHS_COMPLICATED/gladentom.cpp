#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,br,l;
int a[100][100];
vector<int> p;
vector<int> v[100];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)p.push_back(i);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    do
    {
        l=0;if(p[0]!=1)continue;
        for(int i=0;i<n-1;i++)
        {
            if(a[p[i]][p[i+1]]==0){l=1;break;}
        }

        if(a[p[n-1]][1]==0){l=1;}
        if(l==0)
        {
            br++;
            for(int i=0;i<n;i++)v[br].push_back(p[i]);v[br].push_back(1);
        }
    }while(next_permutation(p.begin(),p.end()));
    if(br==0){cout<<-1<<endl;}
    else
    {
        cout<<br<<endl;
        for(int i=1;i<=br;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
