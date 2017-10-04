#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int n,m;
int a[1000][1000];
struct oper
{
    int t,x,y;
};
vector<oper> op;
string s;
oper aa;
int used[1000][1000];
void go(int i,int j)
{
    used[i][j]=1;
    if(used[i-1][j]==0&&a[i-1][j]==4)go(i-1,j);
    if(used[i+1][j]==0&&a[i+1][j]==4)go(i+1,j);
    if(used[i][j-1]==0&&a[i][j-1]==4)go(i,j-1);
    if(used[i][j+1]==0&&a[i][j+1]==4)go(i,j+1);
    //cout<<i<<" "<<j<<endl;
    if(a[i-1][j]==4||a[i+1][j]==4||a[i][j-1]==4||a[i][j+1]==4)
    {a[i][j]=5;aa.t=3;aa.x=i;aa.y=j;
    op.push_back(aa);
    aa.t=2;
    op.push_back(aa);}

}
int main()
{
    //4- blue, 5- red, 1-#, 0-.
    //ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        //cout<<s<<endl;
        for(int j=0;j<m;j++)if(s[j]=='#')a[i][j+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            //cout<<a[i][j]<<endl;
            if(a[i][j]==0){aa.t=1;aa.x=i;aa.y=j;op.push_back(aa),a[i][j]=4;}
        }
        //for(int j=1;j<=n;j++)if(a[i][j]==4&&a[i][j+1]==4){aa.t=3;aa.x=i;aa.y=j;op.push_back(aa);aa.t=2;op.push_back(aa);a[i][j]=5;}
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==4&&used[i][j]==0)go(i,j);
        }
    }
    cout<<op.size()<<endl;
    for(int i=0;i<op.size();i++)
    {
        if(op[i].t==1)printf("B ");
        if(op[i].t==2)printf("R ");
        if(op[i].t==3)printf("D ");
        printf("%d %d\n",op[i].x,op[i].y);
    }
}


