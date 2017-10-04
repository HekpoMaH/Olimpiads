#include<iostream>
using namespace std;
struct p {int x, y;};
pair <p, p> a[1<<10];
int n, ans;
bool v[1<<10][1<<10], used[1<<10];
void dfs(int x)
{
    used[x]=true;
    for(int i=0;i<n;i++) if(!used[i] && v[i][x]) dfs(i);
    return;
}

int D(p a, p b, p c)
{
    int ans=(a.x*b.y + a.y*c.x + b.x*c.y) - (b.y*c.x + a.x*c.y + a.y*b.x);
    if(ans<0) return (-1);
    if(ans>0) return 1;
    if(ans==0) return 0;
}

bool cross(pair<p, p> m, pair <p, p> n)
{
    p a=m.first, b=m.second, c=n.first, d=n.second;
    if(D(a,b,c) != D(a,b,d) && D(c,d,a) != D(c,d,b)) return true;
    if(D(a,b,c) == 0)
        if(c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) &&
           c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y)) return 1;
    if(D(a,b,d) == 0)
        if(d.x >= min(a.x, b.x) && d.x <= max(a.x, b.x) &&
           d.y >= min(a.y, b.y) && d.y <= max(a.y, b.y)) return 1;
    if(D(c,d,a) == 0)
        if(a.x >= min(c.x, d.x) && a.x <= max(c.x, d.x) &&
           a.y >= min(c.y, d.y) && a.y <= max(c.y, d.y)) return 1;
    if(D(c,d,b) == 0)
        if(b.x >= min(c.x, d.x) && b.x <= max(c.x, d.x) &&
           b.y >= min(c.y, d.y) && b.y <= max(c.y, d.y)) return 1;
    return false;
}

int main()
{
    while(scanf("%d%d%d%d", &a[n].first.x, &a[n].first.y, &a[n].second.x, &a[n].second.y) == 4) n++;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j && cross(a[i], a[j]))  v[i][j]=v[j][i]=1;
    dfs(n-1);
    for(int i=0;i<n;i++) ans+=1-used[i];
    cout<<ans<<endl;
    return 0;
}
