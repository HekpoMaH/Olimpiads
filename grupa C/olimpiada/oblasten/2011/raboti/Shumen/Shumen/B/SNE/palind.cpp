#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool a[10001];
int n;
int pal(int x,int y)
{
    while(x<=y)
    {
        if(a[x]!=a[y])
        return 0;
    x++;
    y--;
    }
    return 1;
}
vector<int> v[10001];
stack<int> s;
int blq=0,vu[10001];
void print2(int x,int prev)
{
    if(x==1||x==0)return ;
    if(x==prev){s.push(x-1);vu[x]--;}
    print2(vu[x],x);

}
void print(int x)
{
    cout<<x<<endl;
    blq=1;
    print2(vu[n],n);
    while(!s.empty())
    {
        int t=s.top();
        cout<<t<<' ';
        s.pop();
    }
    //for(int i=1;i<=n;i++)
    //cout<<vu[i]<<' ';
    cout<<endl;
}
int F(int x,int t,int ans,int prev)
{
    int i;
    vu[t-1]=prev;
    if(t==n+1&&blq==0&&ans<=x){print(x);return 1;}
    if(ans>x){return 0;}
    int sz=v[t].size();
    for(i=0;i<sz;i++)
    F(x,v[t][i]+1,ans+1,t);
}

int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)
    if(pal(i,j))v[i].push_back(j);
    if(pal(1,n)){cout<<1<<' '<<0<<endl;return 0;}
    for(i=2;i<=n;i++)
    {
        F(i,1,0,0);
        if(blq==1){return 0;}
    }
    for(i=1;i<=n;i++)
    {
        cout<<i<<" - ";
        for(j=0;j<v[i].size();j++)
        cout<<v[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
