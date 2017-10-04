#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int a[1000][1000],d[1000],pred[1001];
int n,m,x,y,z,starter,ov;
stack<int> s;
int main()
{
    //memset(a,31,sizeof(a));
    //cout<<a[1][1]<<endl;
    ios::sync_with_stdio(false);
    //cout<<"Black hole!"<<endl;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)a[i][j]=-10000000;
    cin>>n>>m;cin>>starter>>ov;
    for(int i=0;i<=n;i++)pred[i]=-1;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;//a[y][x]=z;
    }

    for(int i=0;i<=n;i++)d[i]=a[starter][i];
    for(int k=0;k<=n-2;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(d[i]<min(d[j],a[j][i]))
                {
                    d[i]=min(d[j],a[j][i]);
                    pred[i]=j;
                }
            }
        }
    }
    for(int i=0;i<n;i++){if(i==starter)cout<<"Inf"<<" ";else cout<<d[i]<<" ";}cout<<endl;
    if(d[ov]==0){cout<<"No Path"<<endl;return 0;}

    while(ov!=-1)
    {
        s.push(ov);ov=pred[ov];
    }
    cout<<starter<<" ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";s.pop();
    }
    cout<<endl;
    return 0;
}
