//prepisvam ot en4o
#include<iostream>
#include<vector>
using namespace std;
struct inst
{
    int x,y,z;
};
int n;
int cd;
int r[1009];
int c[1009];
int tab[1009][1009],a,b;
vector<inst> ans;
void solve(int level)
{
    int maxr=0,midx=0,reach;
    inst ass;
    if(level==0)return;
    for(int i=1;i<=level;i++)
    {
        if(r[i]>maxr)
        {
            midx=i;
            maxr=r[i];
        }
    }
    for(int i=1;i<=level;i++)
    {
        if(tab[midx][i]==1&&reach==i)
        {
            reach++;
            continue;
        }
        if(tab[midx][i]==1)
        {
            scol(reach,i);
            ass.x=reach;
            ass.y=i;
            ass.z=2;
            ans.push_back(ass);
            reach++;
        }
    }
    if(midx!=level)
    {
        srow(midx,level);
        ass.x=midx;
        ass.y=level;
        ass.z=1;
        ans.push_back(ass);
    }
    if(cd>=n-1)return;
    
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    cin>>a>>b,r[a]++,c[b]++,tab[a][b]=1;
    solve(n);
}