#include<bits/stdc++.h>
using namespace std;
const int mxn=1009;
struct vec
{
    int x,y;
    vec(){};
    vec(int _x,int _y){x=_x;y=_y;}
    vec operator+ (vec b){return vec(x+b.x,y+b.x);}
    vec operator- (vec b){return vec(x-b.x,y-b.x);}
};
int cross(vec u,vec v)
{
    // |x1 y1|
    // |x2,y2|
    if(u.x*v.y-u.y*v.x>0)return 1;
    if(u.x*v.y-u.y*v.x==0)return 0;
    return -1;
}
int n;
vec triangles[mxn][4];
int gr[mxn][mxn],used[mxn],st[mxn],ans;
void read()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>triangles[i][1].x>>triangles[i][1].y>>triangles[i][2].x>>triangles[i][2].y>>triangles[i][3].x>>triangles[i][3].y;
}
bool leji(vec A,vec B,vec C,vec P)
{
    vec AB=B-A;
    vec BC=C-B;
    vec CA=A-C;
    vec AP=P-A;
    vec BP=P-B;
    vec CP=P-C;
    if(cross(AP,AB)>0&&cross(BP,BC)>0&&cross(CP,CA)>0&&cross(AB,BC)>0)return true;
    if(cross(AP,AB)<0&&cross(BP,BC)<0&&cross(CP,CA)<0&&cross(AB,BC)<0)return true;
    return false;
}
void makeg()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //ako i popada izcqlo v j gr[j][i]=1;
            if(leji(triangles[j][1],triangles[j][2],triangles[j][3],triangles[i][1])==false)continue;
            if(leji(triangles[j][1],triangles[j][2],triangles[j][3],triangles[i][2])==false)continue;
            if(leji(triangles[j][1],triangles[j][2],triangles[j][3],triangles[i][3])==false)continue;
            gr[j][i]=1;
        }
    }
}
void dfs(int node)
{
    int l=1;
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0&&gr[node][i]!=0)
        {
            l=0;
            dfs(i);
            used[node]=max(used[node],used[i]+gr[node][i]);
        }
        if(used[i]==1)
        {
            l=0;
            used[node]=max(used[node],used[i]+gr[node][i]);
        }
    }
    if(l)used[node]=1;
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        if(st[i]==0)
        {
            memset(used,0,sizeof(used));
            used[i]=-1;
            dfs(i);
            for(int k=1;k<=n;k++)
            {
                cout<<used[k]-1<<" ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    makeg();
    cout<<"graph is "<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<i<<" "<<j<<"->";
            cout<<leji(triangles[j][1],triangles[j][2],triangles[j][3],triangles[i][1])<<" ";
            cout<<leji(triangles[j][1],triangles[j][2],triangles[j][3],triangles[i][2])<<" ";
            cout<<leji(triangles[j][1],triangles[j][2],triangles[j][3],triangles[i][3])<<endl;
        }
    }
    solve();
}
