#include<iostream>
#include<cmath>
using namespace std;
int used2[12];
int used[12],ans;
int main()
{
    int n,m,t,b,x,l,y,x1,y1,c;
    cin>>n>>m;
    t=m;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x==m||abs(7-x)==m||y==m||abs(7-y)==m){cout<<"NO"<<endl;return 0;}
    }
    cout<<"YES"<<endl;
    return 0;
}